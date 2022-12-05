#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QVector>

class Game;

class GameObject : public QGraphicsPixmapItem
{
public:
    enum ObjectType {Wall, Player, Air, Door, Winplace, Heal, Keys, Canister, Gun, None};
    enum Dir {Up = 0, Down = 1, Left = 2, Right = 3, Stop = 4, DoorDir = 0};
    static const int Width = 32;

    GameObject(ObjectType, QPixmap);
    ~GameObject();

    ObjectType get_type();
    int get_x();
    int get_y();
    int get_score();
    void set_score(int);
    void set_dir(Dir);
    void set_next_dir(Dir);
    Dir get_dir();
    Dir get_next_dir();

    friend class Game;
protected:
    int _x, _y;
    Dir dir;
    Dir next_dir;
    ObjectType type;
    int score;

};

class Player : public GameObject
{
public:
    Player();
    void player_move_up();
    void player_move_down();
    void player_move_left();
    void player_move_right();
    Game *game;
    friend class Game;
private:
    void moveup();
    void movedown();
    void moveleft();
    void moveright();
    bool overlapable(int, int);
    void cheakToWin();
    QVector<QPixmap> anim[4];
    QVector<ObjectType> vecIn = {None, None, None, None, Canister, Keys};
    bool Car_Keys = false;
    bool Canister_of_gas = false;
    int anim_index;
};
#endif // GAMEOBJECT_H
