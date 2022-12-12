#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QVector>
#include <QList>
class Game;

class GameObject : public QGraphicsPixmapItem
{
public:
    enum ObjectType {Zombie = 0, Pistol = 1, Knife = 2, Heal = 3, Keys = 4, Canister = 5, Air = 6, Gun = 7, None = 8, Wall, Player, Ticket, Door, Winplace, Heart};
    enum Dir {Up = 0, Down = 1, Left = 2, Right = 3, Stop = 4};
    static const int Width = 32;

    GameObject(ObjectType, QPixmap);
    ~GameObject();

    ObjectType get_type();
    int get_x();
    int get_y();
    int get_score();
    void set_score(int);

    friend class Game;
protected:
    int _x, _y;
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
    void addToInv(ObjectType,int,int, int);
    QVector<QPixmap> anim[4];
    ObjectType *vecIn;
    //QVector<ObjectType> vecIn = {None, None, None, None, None, None};
    bool Car_Keys = false;
    bool Canister_of_gas = false;
};

class Ticket: public GameObject
{
public:
    Ticket(ObjectType);
    void anim();
    void healAction();
    ObjectType randTicket();
    ObjectType noneTicket();
    void setAnimTicket(int i, int j);
    QVector<QVector<ObjectType>> cardMap;
    QVector<QVector<Ticket*>> cards;
    Game *game;
    int tickets = 46;
    friend class game;
    friend class Inventory;
    QVector<QPixmap> animCard[10];
    QVector<QPixmap> animInv[10];
    QVector<QPixmap> animHeart;
private:

    QVector<ObjectType> winItems = {Keys, Canister};
    QVector<ObjectType> zombies = {Zombie, Zombie, Zombie, Zombie, Zombie, Zombie, Zombie, Zombie, Zombie,
                                  Zombie, Zombie, Zombie, Zombie, Zombie, Zombie, Zombie, Zombie, Zombie,
                                  Zombie, Zombie, Zombie, Zombie, Zombie, Zombie, Zombie, Zombie, Zombie,
                                  Zombie};
    QVector<ObjectType> guns = {Pistol, Knife, Pistol, Knife, Pistol, Knife, Pistol, Knife, Pistol, Knife};
    QVector<ObjectType> firstAidKit = {Heal, Heal, Heal, Heal, Heal, Heal};


};
#endif // GAMEOBJECT_H
