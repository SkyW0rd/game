#include "game.h"
#include <QString>
#include <QFile>
#include <QRandomGenerator>
#define W (GameObject::Width)
Game::Game(int x, int y, int map_w, int map_h, QString map_src):QGraphicsScene(x,y,W*map_w, W*map_h)
{
    geo_x = x;
    geo_y = y;
    stat = Playing;

    map_size = map_w * map_h;
    map_width = map_w;
    map_height = map_h;
    map = new GameObject**[map_height];
    ticket = new Ticket(GameObject::None);
    for(int i = 0; i < map_height; i++)
    {
        QVector<Ticket::ObjectType> tempVec;
        QVector<Ticket*> tmpTicket;
        map[i] = new GameObject*[map_width];
        for(int j = 0; j < map_width; j++)
        {
            map[i][j] = nullptr;
            tempVec.push_back(GameObject::None);
            tmpTicket.push_back(nullptr);
        }
        ticket->cardMap.push_back(tempVec);
        ticket->cards.push_back(tmpTicket);
    }
    QPixmap earthpix(":/image/earth1.png");
    QPixmap fieldpix(":/image/field.png");
    QPixmap floorpix(":/image/floor1.png");
    QPixmap wallpix(":/image/wall.png");
    QPixmap doorpix(":/image/door.png");
    QPixmap winplacepix(":/image/winplace.png");
    QPixmap heartpix(":/image/heart.png");
    QPixmap facepix(":/image/head.png");
    QFile mapfile(map_src);
    mapfile.open(QIODevice::ReadOnly | QIODevice::Text);
    for(int i = 0; i < map_h; i++)
    {
        QByteArray line  = mapfile.readLine();
        for(int j = 0; j < map_w; j++)
        {
            int tmp_x = x + (j * W);
            int tmp_y = y + (i * W);
            QVector<int> temp_x_y_Inv;
            switch(line[j])
            {
                case '0':
                    map[i][j] = new GameObject(GameObject::Air, earthpix);
                    map[i][j]->setPos(tmp_x, tmp_y);
                    addItem(map[i][j]);
                    if(qrand() % ((3 + 1) - 0) + 0 == 1 && ticket->tickets != 0)
                    {
                        ticket->tickets--;
                        card = new Ticket(GameObject::None);
                        card->game = this;
                        card->setZValue(1);
                        card->setPos(tmp_x, tmp_y);
                        addItem(card);
                        map[i][j] = card;
                        ticket->cardMap[i][j] = ticket->randTicket();
                        ticket->cards[i][j] = card;
                    }
                    break;
                case '1':
                    map[i][j] = new GameObject(GameObject::Wall, wallpix);
                    map[i][j]->setPos(tmp_x, tmp_y);
                    addItem(map[i][j]);
                    break;
                case '3':
                    map[i][j] = new GameObject(GameObject::Wall, fieldpix);
                    map[i][j]->setPos(tmp_x, tmp_y);
                    addItem(map[i][j]);
                    break;
                case '4':
                    map[i][j] = new GameObject(GameObject::Air, floorpix);
                    map[i][j]->setPos(tmp_x, tmp_y);
                    addItem(map[i][j]);
                    if(qrand() % ((2 + 1) - 0) + 0 == 1 && ticket->tickets != 0)
                    {
                        ticket->tickets--;
                        card = new Ticket(GameObject::Ticket);
                        card->game = this;
                        card->setZValue(1);
                        card->setPos(tmp_x, tmp_y);
                        addItem(card);
                        map[i][j] = card;
                        ticket->cardMap[i][j] = ticket->randTicket();
                        ticket->cards[i][j] = card;
                    }
                    break;
                case '5':
                    map[i][j] = new GameObject(GameObject::Door, doorpix);
                    map[i][j]->setPos(tmp_x, tmp_y);
                    addItem(map[i][j]);
                    break;
                case '9':

                    card = new Ticket(GameObject::Gun);
                    card->game = this;
                    card->setZValue(1);
                    card->setPos(tmp_x, tmp_y);
                    addItem(card);
                    map[i][j] = card;
                    ticket->cardMap[i][j] = GameObject::Gun;
                    ticket->cards[i][j] = card;
                    qDebug() << tmp_x << " " << tmp_y;
                    temp_x_y_Inv.push_back(i);
                    temp_x_y_Inv.push_back(j);
                    x_y_Inv.push_back(temp_x_y_Inv);
                    break;
                case 'p':
                    map[i][j] = new GameObject(GameObject::Air, earthpix);
                    map[i][j]->setPos(tmp_x, tmp_y);
                    addItem(map[i][j]);
                    player = new Player();
                    player->game = this;
                    player->setZValue(2);
                    player->setPos(tmp_x, tmp_y);
                    addItem(player);
                    map[i][j] = player;
                    break;
                case 'w':
                    map[i][j] = new GameObject(GameObject::Air, earthpix);
                    map[i][j]->setPos(tmp_x, tmp_y);
                    addItem(map[i][j]);
                    map[i][j] = new GameObject(GameObject::Winplace, winplacepix);
                    map[i][j]->setPos(tmp_x, tmp_y);
                    addItem(map[i][j]);
                    break;
                case 'h':
                    map[i][j] = new GameObject(GameObject::Wall, heartpix);
                    map[i][j]->setPos(tmp_x, tmp_y);
                    addItem(map[i][j]);
                    lifePlayer++;
                    break;
                case 'f':
                    map[i][j] = new GameObject(GameObject::Wall, facepix);
                    map[i][j]->setPos(tmp_x, tmp_y);
                    addItem(map[i][j]);
                    break;
            }
            if(map[i][j])
            {
                map[i][j]->_x = j;
                map[i][j]->_y = i;
            }
        }
    }
}
void Game::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    if(stat == Game::Question)
    {
        if(e->scenePos().x() >= 640 && e->scenePos().x() <= 671 && e->scenePos().y() >= 224 && e->scenePos().y() <= 255)
        {
            int X = (static_cast<int>(e->scenePos().x()) - geo_x) / W;
            int Y = (static_cast<int>(e->scenePos().y()) - geo_y) / W;
            if(ticket->cardMap[Y][X] == GameObject::Gun)
            {
                player->addToInv(ticket->cardMap[geo_y][geo_x], Y, X, 0);
            }
            else if (ticket->cardMap[Y][X] != ticket->cardMap[geo_y][geo_x])
            {
                GameObject::ObjectType type = ticket->cardMap[geo_y][geo_x];
                ticket->cardMap[geo_y][geo_x] = ticket->cardMap[Y][X];
                ticket->cardMap[Y][X] = type;
                player->vecIn[0] = type;

                ticket->cardMap[geo_y][geo_x] = ticket->cardMap[geo_y][geo_x];
                ticket->cards[geo_y][geo_x]->setPixmap(ticket->animCard[ticket->cardMap[geo_y][geo_x]][0]);

                ticket->cardMap[Y][X] = ticket->cardMap[Y][X];
                ticket->cards[Y][X]->setPixmap(ticket->animInv[ticket->cardMap[Y][X]][0]);
            }
            stat = Game::Playing;
        }
        if(e->scenePos().x() >= 672 && e->scenePos().x() <= 703 && e->scenePos().y() >= 224 && e->scenePos().y() <= 255)
        {
            int X = (static_cast<int>(e->scenePos().x()) - geo_x) / W;
            int Y = (static_cast<int>(e->scenePos().y()) - geo_y) / W;
            if(ticket->cardMap[Y][X] == GameObject::Gun)
            {
                player->addToInv(ticket->cardMap[geo_y][geo_x], Y, X, 1);
            }
            else if (ticket->cardMap[Y][X] != ticket->cardMap[geo_y][geo_x])
            {
                GameObject::ObjectType type = ticket->cardMap[geo_y][geo_x];
                ticket->cardMap[geo_y][geo_x] = ticket->cardMap[Y][X];
                ticket->cardMap[Y][X] = type;
                player->vecIn[1] = type;

                ticket->cardMap[geo_y][geo_x] = ticket->cardMap[geo_y][geo_x];
                ticket->cards[geo_y][geo_x]->setPixmap(ticket->animCard[ticket->cardMap[geo_y][geo_x]][0]);

                ticket->cardMap[Y][X] = ticket->cardMap[Y][X];
                ticket->cards[Y][X]->setPixmap(ticket->animInv[ticket->cardMap[Y][X]][0]);
            }
            stat = Game::Playing;
        }
        else if(e->scenePos().x() >= 704 && e->scenePos().x() <= 735 && e->scenePos().y() >= 224 && e->scenePos().y() <= 255)
        {
            int X = (static_cast<int>(e->scenePos().x()) - geo_x) / W;
            int Y = (static_cast<int>(e->scenePos().y()) - geo_y) / W;
            if(ticket->cardMap[Y][X] == GameObject::Gun)
            {
                player->addToInv(ticket->cardMap[geo_y][geo_x], Y, X, 2);
            }
            else if (ticket->cardMap[Y][X] != ticket->cardMap[geo_y][geo_x])
            {
                GameObject::ObjectType type = ticket->cardMap[geo_y][geo_x];
                ticket->cardMap[geo_y][geo_x] = ticket->cardMap[Y][X];
                ticket->cardMap[Y][X] = type;
                player->vecIn[2] = type;

                ticket->cardMap[geo_y][geo_x] = ticket->cardMap[geo_y][geo_x];
                ticket->cards[geo_y][geo_x]->setPixmap(ticket->animCard[ticket->cardMap[geo_y][geo_x]][0]);

                ticket->cardMap[Y][X] = ticket->cardMap[Y][X];
                ticket->cards[Y][X]->setPixmap(ticket->animInv[ticket->cardMap[Y][X]][0]);
            }
            stat = Game::Playing;
        }
        else if(e->scenePos().x() >= 736 && e->scenePos().x() <= 767 && e->scenePos().y() >= 224 && e->scenePos().y() <= 255)
        {
            int X = (static_cast<int>(e->scenePos().x()) - geo_x) / W;
            int Y = (static_cast<int>(e->scenePos().y()) - geo_y) / W;
            if(ticket->cardMap[Y][X] == GameObject::Gun)
            {
                player->addToInv(ticket->cardMap[geo_y][geo_x], Y, X, 3);
            }
            else if (ticket->cardMap[Y][X] != ticket->cardMap[geo_y][geo_x])
            {
                GameObject::ObjectType type = ticket->cardMap[geo_y][geo_x];
                ticket->cardMap[geo_y][geo_x] = ticket->cardMap[Y][X];
                ticket->cardMap[Y][X] = type;
                player->vecIn[3] = type;

                ticket->cardMap[geo_y][geo_x] = ticket->cardMap[geo_y][geo_x];
                ticket->cards[geo_y][geo_x]->setPixmap(ticket->animCard[ticket->cardMap[geo_y][geo_x]][0]);

                ticket->cardMap[Y][X] = ticket->cardMap[Y][X];
                ticket->cards[Y][X]->setPixmap(ticket->animInv[ticket->cardMap[Y][X]][0]);
            }
            stat = Game::Playing;
        }
        else if(e->scenePos().x() >= 768 && e->scenePos().x() <= 799 && e->scenePos().y() >= 224 && e->scenePos().y() <= 255)
        {
            int X = (static_cast<int>(e->scenePos().x()) - geo_x) / W;
            int Y = (static_cast<int>(e->scenePos().y()) - geo_y) / W;
            if(ticket->cardMap[Y][X] == GameObject::Gun)
            {
                player->addToInv(ticket->cardMap[geo_y][geo_x], Y, X, 4);
            }
            else if (ticket->cardMap[Y][X] != ticket->cardMap[geo_y][geo_x])
            {
                GameObject::ObjectType type = ticket->cardMap[geo_y][geo_x];
                ticket->cardMap[geo_y][geo_x] = ticket->cardMap[Y][X];
                ticket->cardMap[Y][X] = type;
                player->vecIn[4] = type;

                ticket->cardMap[geo_y][geo_x] = ticket->cardMap[geo_y][geo_x];
                ticket->cards[geo_y][geo_x]->setPixmap(ticket->animCard[ticket->cardMap[geo_y][geo_x]][0]);

                ticket->cardMap[Y][X] = ticket->cardMap[Y][X];
                ticket->cards[Y][X]->setPixmap(ticket->animInv[ticket->cardMap[Y][X]][0]);
            }
            stat = Game::Playing;
        }
        else if(e->scenePos().x() >= 800 && e->scenePos().x() <= 831 && e->scenePos().y() >= 224 && e->scenePos().y() <= 255)
        {
            int X = (static_cast<int>(e->scenePos().x()) - geo_x) / W;
            int Y = (static_cast<int>(e->scenePos().y()) - geo_y) / W;
            if(ticket->cardMap[Y][X] == GameObject::Gun)
            {
                player->addToInv(ticket->cardMap[geo_y][geo_x], Y, X, 5);
            }
            else if (ticket->cardMap[Y][X] != ticket->cardMap[geo_y][geo_x])
            {
                GameObject::ObjectType type = ticket->cardMap[geo_y][geo_x];
                ticket->cardMap[geo_y][geo_x] = ticket->cardMap[Y][X];
                ticket->cardMap[Y][X] = type;
                player->vecIn[5] = type;

                ticket->cardMap[geo_y][geo_x] = ticket->cardMap[geo_y][geo_x];
                ticket->cards[geo_y][geo_x]->setPixmap(ticket->animCard[ticket->cardMap[geo_y][geo_x]][0]);

                ticket->cardMap[Y][X] = ticket->cardMap[Y][X];
                ticket->cards[Y][X]->setPixmap(ticket->animInv[ticket->cardMap[Y][X]][0]);
            }
            stat = Game::Playing;
        }
    }
}
void Game::start()
{

}

void Game::stop()
{

}

int Game::giveAction()
{
    return(qrand()%((4 + 1) - 1) + 1);
}
Game::~Game()
{
    for (int i = 0; i < map_height; i++)
    {
            for (int j = 0; j < map_width; j++)
            {
                if (map[i][j] != nullptr)
                    delete map[i][j];
            }
            delete[] map[i];
        }
}
