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


    for(int i = 0; i < map_height; i++)
    {
        map[i] = new GameObject*[map_width];
        for(int j = 0; j < map_width; j++)
        {
            map[i][j] = nullptr;
        }
    }
    QPixmap earthpix("C:\\Users\\Zalman N3\\Desktop\\game\\game\\res\\image\\earth1.png");
    QPixmap fieldpix("C:\\Users\\Zalman N3\\Desktop\\game\\game\\res\\image\\field.png");
    QPixmap floorpix("C:\\Users\\Zalman N3\\Desktop\\game\\game\\res\\image\\floor1.png");
    QPixmap wallpix("C:\\Users\\Zalman N3\\Desktop\\game\\game\\res\\image\\wall.png");
    QPixmap doorpix("C:\\Users\\Zalman N3\\Desktop\\game\\game\\res\\image\\door.png");
    QPixmap winplacepix("C:\\Users\\Zalman N3\\Desktop\\game\\game\\res\\image\\winplace.png");
    QPixmap inventorypix("C:\\Users\\Zalman N3\\Desktop\\game\\game\\res\\image\\inventory.png");
    QPixmap heartpix("C:\\Users\\Zalman N3\\Desktop\\game\\game\\res\\image\\heart.png");
    QPixmap facepix("C:\\Users\\Zalman N3\\Desktop\\game\\game\\res\\image\\head.png");
    QFile mapfile(map_src);
    mapfile.open(QIODevice::ReadOnly | QIODevice::Text);

    player = new Player();

    for(int i = 0; i < map_h; i++)
    {
        QByteArray line  = mapfile.readLine();
        for(int j = 0; j < map_w; j++)
        {
            int tmp_x = x + (j * W);
            int tmp_y = y + (i * W);
            switch(line[j])
            {
                case '0':
                    map[i][j] = new GameObject(GameObject::Air, earthpix);
                    map[i][j]->setPos(tmp_x, tmp_y);
                    addItem(map[i][j]);
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
                    break;
                case '5':
                    map[i][j] = new GameObject(GameObject::Door, doorpix);
                    map[i][j]->setPos(tmp_x, tmp_y);
                    addItem(map[i][j]);
                    break;
                case '9':
                    map[i][j] = new GameObject(GameObject::Wall, inventorypix);
                    map[i][j]->setPos(tmp_x, tmp_y);
                    addItem(map[i][j]);
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
