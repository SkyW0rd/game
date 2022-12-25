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
#include <QList>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

class Game: public QGraphicsScene
{
    Q_OBJECT
public:
    enum GameStatus {Playing, Win, Lose, Pause, Question, MiniGame};
    Game(int, int, int, int, QString);
    ~Game();

    void mousePressEvent(QGraphicsSceneMouseEvent*) override;
    void start();
    void stop();
    QVector<QVector<GameObject*>> map;
    //GameObject ***map;
    GameStatus stat;
    Ticket *ticket;
    Player *player;
    Ticket *card;
    QVector<Ticket*> cards;
    int lifePlayer = 0;
    QVector<QVector<int>> x_y_Inv;
    QVector<QVector<int>> x_y_Heart;
    int actionPlayer = 0;
    QVector<QVector<int>> vecZombie;

    friend class Player;
    friend class Ticket;
private slots:

private:
    int map_height, map_width;
    int map_size;
    int geo_x, geo_y;

};
#endif // GAME_H
