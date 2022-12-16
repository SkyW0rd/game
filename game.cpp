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
    ticket = new Ticket(GameObject::None);
    for(int i = 0; i < map_height; i++)
    {
        QVector<Ticket::ObjectType> tempVec;
        QVector<Ticket*> tmpTicket;
        QVector<GameObject*> tmpMap;
        for(int j = 0; j < map_width; j++)
        {
            tmpMap.push_back(nullptr);
            tempVec.push_back(GameObject::None);
            tmpTicket.push_back(nullptr);
        }
        map.push_back(tmpMap);
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
    QPixmap gameButtonpix(":/image/gamebutton.png");
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
            QVector<int> tempXY;
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
                    if(i == 0 && j == 0)
                    {
                        map[i][j] = new GameObject(GameObject::Air, fieldpix);
                    }
                    else
                    {
                        map[i][j] = new GameObject(GameObject::Wall, fieldpix);
                    }
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
                    map[i][j] = new GameObject(GameObject::Air, doorpix);
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
                    card = new Ticket(GameObject::Heart);
                    card->game = this;
                    card->setZValue(1);
                    card->setPos(tmp_x, tmp_y);
                    addItem(card);
                    map[i][j] = card;
                    ticket->cardMap[i][j] = GameObject::Heart;
                    ticket->cards[i][j] = card;
                    lifePlayer++;
                    tempXY.push_back(i);
                    tempXY.push_back(j);
                    x_y_Heart.push_back(tempXY);
                    break;
                case 'f':
                    map[i][j] = new GameObject(GameObject::Wall, facepix);
                    map[i][j]->setPos(tmp_x, tmp_y);
                    addItem(map[i][j]);
                    break;
                case 'b':
                    map[i][j] = new GameObject(GameObject::Air, gameButtonpix);
                    map[i][j]->setPos(tmp_x, tmp_y);
                    addItem(map[i][j]);
                    qDebug() << tmp_x << " " << tmp_y;
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
            int X = (static_cast<int>(e->scenePos().x())) / W;
            int Y = (static_cast<int>(e->scenePos().y())) / W;
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
            int X = (static_cast<int>(e->scenePos().x())) / W;
            int Y = (static_cast<int>(e->scenePos().y())) / W;
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
            int X = (static_cast<int>(e->scenePos().x())) / W;
            int Y = (static_cast<int>(e->scenePos().y())) / W;
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
            int X = (static_cast<int>(e->scenePos().x())) / W;
            int Y = (static_cast<int>(e->scenePos().y())) / W;
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
            int X = (static_cast<int>(e->scenePos().x())) / W;
            int Y = (static_cast<int>(e->scenePos().y())) / W;
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
            int X = (static_cast<int>(e->scenePos().x())) / W;
            int Y = (static_cast<int>(e->scenePos().y())) / W;
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
    else if(stat == Game::MiniGame)
    {
        if(e->scenePos().x() >= 640 && e->scenePos().x() <= 671 && e->scenePos().y() >= 128 && e->scenePos().y() <= 159)
        {
            actionPlayer = 0;
            int rand = (qrand() % ((10 + 1) - 1) + 1);
            bool flag = false;
            switch(rand)
            {
                /*case 1:
                    lifePlayer--;
                    if(lifePlayer != 0)
                    {
                        ticket->cards[x_y_Heart[lifePlayer][0]][x_y_Heart[lifePlayer][1]]->setPixmap(ticket->animHeart[1]);
                    }
                    else
                    {
                        ticket->cards[x_y_Heart[lifePlayer][0]][x_y_Heart[lifePlayer][1]]->setPixmap(ticket->animHeart[1]);
                        stat = Game::Lose;
                    }
                    break;
                case 2:
                    lifePlayer--;
                    if(lifePlayer != 0)
                    {
                        ticket->cards[x_y_Heart[lifePlayer][0]][x_y_Heart[lifePlayer][1]]->setPixmap(ticket->animHeart[1]);
                    }
                    else
                    {
                        ticket->cards[x_y_Heart[lifePlayer][0]][x_y_Heart[lifePlayer][1]]->setPixmap(ticket->animHeart[1]);
                        stat = Game::Lose;
                    }
                    break;
                case 3:
                    lifePlayer--;
                    if(lifePlayer != 0)
                    {
                        ticket->cards[x_y_Heart[lifePlayer][0]][x_y_Heart[lifePlayer][1]]->setPixmap(ticket->animHeart[1]);
                    }
                    else
                    {
                        ticket->cards[x_y_Heart[lifePlayer][0]][x_y_Heart[lifePlayer][1]]->setPixmap(ticket->animHeart[1]);
                        stat = Game::Lose;
                    }
                    break;*/
                case 4:
                    for(int k = 0; k < 6; k++)
                    {
                        if(player->vecIn[k] == GameObject::Pistol && flag == false)
                        {
                            ticket->cardMap[x_y_Inv[k][0]][x_y_Inv[k][1]] = GameObject::Gun;
                            ticket->cards[x_y_Inv[k][0]][x_y_Inv[k][1]]->setPixmap(ticket->animInv[GameObject::Gun][0]);

                            ticket->cardMap[geo_y][geo_x] = GameObject::None;
                            ticket->cards[geo_y][geo_x]->setPixmap(ticket->animCard[GameObject::Air][0]);
                            //ticket->cards[geo_y][geo_x] = ticket->cards[1][1];
                            //ticket->cards[vecZombie[0][0]][vecZombie[0][1]] = Ticket::Hidden;
                            map[geo_y][geo_x] = map[0][0];
                            ticket->cards[geo_y][geo_x] = ticket->cards[0][0];

                            flag = true;
                            player->vecIn[k] = GameObject::None;
                            stat = Game::Playing;
                            int n = 0;
                            for(int i = 0; i < vecZombie.size(); i++)
                            {
                                if(vecZombie[i][0] == geo_y && vecZombie[i][1] == geo_x)
                                {
                                    n = i;
                                }
                            }
                            if(vecZombie.begin() != vecZombie.end())
                            {
                                vecZombie.erase(vecZombie.begin() + n, vecZombie.begin() + n + 1);
                            }
                            else
                            {
                                vecZombie.pop_back();
                            }
                            //ticket->cards[vecZombie[0][0]][vecZombie[0][]] = Ticket::Hidden;
                            break;
                        }
                    }
                    break;
                case 5:
                    for(int k = 0; k < 6; k++)
                    {
                        if(player->vecIn[k] == GameObject::Pistol && flag == false)
                        {
                            ticket->cardMap[x_y_Inv[k][0]][x_y_Inv[k][1]] = GameObject::Gun;
                            ticket->cards[x_y_Inv[k][0]][x_y_Inv[k][1]]->setPixmap(ticket->animInv[GameObject::Gun][0]);

                            ticket->cardMap[geo_y][geo_x] = GameObject::None;
                            ticket->cards[geo_y][geo_x]->setPixmap(ticket->animCard[GameObject::Air][0]);
                            //ticket->cards[geo_y][geo_x]  = ticket->cards[1][1];
                            map[geo_y][geo_x] = map[0][0];
                            ticket->cards[geo_y][geo_x] = ticket->cards[0][0];
                            flag = true;
                            player->vecIn[k] = GameObject::None;
                            stat = Game::Playing;
                            int n = 0;
                            for(int i = 0; i < vecZombie.size(); i++)
                            {
                                if(vecZombie[i][0] == geo_y && vecZombie[i][1] == geo_x)
                                {
                                    n = i;
                                }
                            }
                            if(vecZombie.begin() != vecZombie.end())
                            {
                                vecZombie.erase(vecZombie.begin() + n, vecZombie.begin() + n + 1);
                            }
                            else
                            {
                                vecZombie.pop_back();
                            }
                            ticket->status = Ticket::Hidden;
                            break;
                        }
                    }
                    break;
                case 6:
                    for(int k = 0; k < 6; k++)
                    {
                        if(player->vecIn[k] == GameObject::Knife && flag == false)
                        {
                            ticket->cardMap[x_y_Inv[k][0]][x_y_Inv[k][1]] = GameObject::Gun;
                            ticket->cards[x_y_Inv[k][0]][x_y_Inv[k][1]]->setPixmap(ticket->animInv[GameObject::Gun][0]);

                            ticket->cardMap[geo_y][geo_x] = GameObject::None;
                            ticket->cards[geo_y][geo_x]->setPixmap(ticket->animCard[GameObject::Air][0]);
                            //ticket->cards[geo_y][geo_x]  = ticket->cards[1][1];

                            map[geo_y][geo_x] = map[0][0];
                            ticket->cards[geo_y][geo_x] = ticket->cards[0][0];
                            flag = true;
                            player->vecIn[k] = GameObject::None;
                            stat = Game::Playing;
                            int n = 0;
                            for(int i = 0; i < vecZombie.size(); i++)
                            {
                                if(vecZombie[i][0] == geo_y && vecZombie[i][1] == geo_x)
                                {
                                    n = i;
                                }
                            }
                            if(vecZombie.begin() != vecZombie.end())
                            {
                                vecZombie.erase(vecZombie.begin() + n, vecZombie.begin() + n + 1);
                            }
                            else
                            {
                                vecZombie.pop_back();
                            }
                            ticket->status = Ticket::Hidden;
                            break;
                        }
                    }
                    break;
                case 7:
                    for(int k = 0; k < 6; k++)
                    {
                        if(player->vecIn[k] == GameObject::Knife && flag == false)
                        {
                            ticket->cardMap[x_y_Inv[k][0]][x_y_Inv[k][1]] = GameObject::Gun;
                            ticket->cards[x_y_Inv[k][0]][x_y_Inv[k][1]]->setPixmap(ticket->animInv[GameObject::Gun][0]);

                            ticket->cardMap[geo_y][geo_x] = GameObject::None;
                            ticket->cards[geo_y][geo_x]->setPixmap(ticket->animCard[GameObject::Air][0]);

                            map[geo_y][geo_x] = map[0][0];
                            ticket->cards[geo_y][geo_x] = ticket->cards[0][0];


                            flag = true;
                            player->vecIn[k] = GameObject::None;
                            stat = Game::Playing;
                            int n = 0;
                            for(int i = 0; i < vecZombie.size(); i++)
                            {
                                if(vecZombie[i][0] == geo_y && vecZombie[i][1] == geo_x)
                                {
                                    n = i;
                                }
                            }
                            if(vecZombie.begin() != vecZombie.end())
                            {
                                vecZombie.erase(vecZombie.begin() + n, vecZombie.begin() + n + 1);
                            }
                            else
                            {
                                vecZombie.pop_back();
                            }
                            ticket->status = Ticket::Hidden;
                            break;
                        }
                    }
                    break;
                case 8:
                    stat = Game::Playing;
                    break;
                case 9:
                    stat = Game::Playing;
                    break;
                case 10:
                    stat = Game::Playing;
                    break;
                default:
                    stat = Game::Playing;
                    break;
            }
        }
    }
    else if(stat == Game::Playing)
    {
        int X = (static_cast<int>(e->scenePos().x())) / W;
        int Y = (static_cast<int>(e->scenePos().y())) / W;
        if(e->scenePos().x() >= 640 && e->scenePos().x() <= 671 && e->scenePos().y() >= 224 && e->scenePos().y() <= 255)
        {
            if(ticket->cardMap[Y][X] == GameObject::Heal)
            {
                for(int i = 0 ; i < 3; i++)
                {
                    if(lifePlayer != 5)
                    {
                        ticket->cards[x_y_Heart[lifePlayer][0]][x_y_Heart[lifePlayer][1]]->setPixmap(ticket->animHeart[0]);
                        lifePlayer++;
                        ticket->cardMap[x_y_Inv[0][0]][x_y_Inv[0][1]] = GameObject::Gun;
                        ticket->cards[x_y_Inv[0][0]][x_y_Inv[0][1]]->setPixmap(ticket->animInv[GameObject::Gun][0]);
                    }
                }
            }
        }
        else if(e->scenePos().x() >= 672 && e->scenePos().x() <= 703 && e->scenePos().y() >= 224 && e->scenePos().y() <= 255)
        {
            if(ticket->cardMap[Y][X] == GameObject::Heal)
            {
                for(int i = 0 ; i < 3; i++)
                {
                    if(lifePlayer != 5)
                    {
                        ticket->cards[x_y_Heart[lifePlayer][0]][x_y_Heart[lifePlayer][1]]->setPixmap(ticket->animHeart[0]);
                        lifePlayer++;
                        ticket->cardMap[x_y_Inv[1][0]][x_y_Inv[1][1]] = GameObject::Gun;
                        ticket->cards[x_y_Inv[1][0]][x_y_Inv[1][1]]->setPixmap(ticket->animInv[GameObject::Gun][0]);
                    }
                }
            }
        }
        else if(e->scenePos().x() >= 704 && e->scenePos().x() <= 735 && e->scenePos().y() >= 224 && e->scenePos().y() <= 255)
        {
            if(ticket->cardMap[Y][X] == GameObject::Heal)
            {
                for(int i = 0 ; i < 3; i++)
                {
                    if(lifePlayer != 5)
                    {
                        ticket->cards[x_y_Heart[lifePlayer][0]][x_y_Heart[lifePlayer][1]]->setPixmap(ticket->animHeart[0]);
                        lifePlayer++;
                        ticket->cardMap[x_y_Inv[2][0]][x_y_Inv[2][1]] = GameObject::Gun;
                        ticket->cards[x_y_Inv[2][0]][x_y_Inv[2][1]]->setPixmap(ticket->animInv[GameObject::Gun][0]);
                    }
                }
            }
        }
        else if(e->scenePos().x() >= 736 && e->scenePos().x() <= 767 && e->scenePos().y() >= 224 && e->scenePos().y() <= 255)
        {
            if(ticket->cardMap[Y][X] == GameObject::Heal)
            {
                for(int i = 0 ; i < 3; i++)
                {
                    if(lifePlayer != 5)
                    {
                        ticket->cards[x_y_Heart[lifePlayer][0]][x_y_Heart[lifePlayer][1]]->setPixmap(ticket->animHeart[0]);
                        lifePlayer++;
                        ticket->cardMap[x_y_Inv[3][0]][x_y_Inv[3][1]] = GameObject::Gun;
                        ticket->cards[x_y_Inv[3][0]][x_y_Inv[3][1]]->setPixmap(ticket->animInv[GameObject::Gun][0]);
                    }
                }
            }
        }
        else if(e->scenePos().x() >= 768 && e->scenePos().x() <= 799 && e->scenePos().y() >= 224 && e->scenePos().y() <= 255)
        {
            if(ticket->cardMap[Y][X] == GameObject::Heal)
            {
                for(int i = 0 ; i < 3; i++)
                {
                    if(lifePlayer != 5)
                    {
                        ticket->cards[x_y_Heart[lifePlayer][0]][x_y_Heart[lifePlayer][1]]->setPixmap(ticket->animHeart[0]);
                        lifePlayer++;
                        ticket->cardMap[x_y_Inv[4][0]][x_y_Inv[4][1]] = GameObject::Gun;
                        ticket->cards[x_y_Inv[4][0]][x_y_Inv[4][1]]->setPixmap(ticket->animInv[GameObject::Gun][0]);
                    }
                }
            }
        }
        else if(e->scenePos().x() >= 800 && e->scenePos().x() <= 831 && e->scenePos().y() >= 224 && e->scenePos().y() <= 255)
        {
            qDebug() << lifePlayer;
            if(ticket->cardMap[Y][X] == GameObject::Heal)
            {
                for(int i = 0 ; i < 3; i++)
                {
                    if(lifePlayer != 5)
                    {
                        ticket->cards[x_y_Heart[lifePlayer][0]][x_y_Heart[lifePlayer][1]]->setPixmap(ticket->animHeart[0]);
                        lifePlayer++;
                        ticket->cardMap[x_y_Inv[5][0]][x_y_Inv[5][1]] = GameObject::Gun;
                        ticket->cards[x_y_Inv[5][0]][x_y_Inv[5][1]]->setPixmap(ticket->animInv[GameObject::Gun][0]);
                    }
                }
            }
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
    map.clear();
    vecZombie.clear();
    x_y_Inv.clear();
    x_y_Heart.clear();
    cards.clear();
    lifePlayer = 0;
    action = 0;

}
