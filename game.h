#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QPair>
#include <QVector>
#include <QMessageBox>
#include "gameobject.h"
#include <QRandomGenerator>


class Game: public QGraphicsScene
{
    Q_OBJECT
public:
    enum GameStatus {Playing, Win, Lose, Pause};
    Game(int, int, int, int, QString);
    ~Game();

    void start();
    void stop();
    GameObject ***map;
    GameStatus stat;
    Player *player;
    int lifePlayer = 0;
    int action = 0;
    void cheakHP();
    int giveAction();
    friend class Player;
private slots:

private:
    int map_height, map_width;
    int map_size;
    int geo_x, geo_y;

    QTimer *player_timer;

};
#endif // GAME_H
