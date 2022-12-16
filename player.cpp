#include "game.h"
#define W (GameObject::Width)

Player::Player() : GameObject(
    GameObject::Player, QPixmap(":/image/catFront.png"))
{
     anim[Right].push_back(QPixmap(":/image/catRight.png"));

     anim[Up].push_back(QPixmap(":/image/catBack.png"));

     anim[Left].push_back(QPixmap(":/image/catLeft.png"));

     anim[Down].push_back(QPixmap(":/image/catFront.png"));

     vecIn = new ObjectType[6];
     for(int i = 0; i < 10; i++)
     {
         vecIn[i] = None;
     }
}
void Player::cheakToWin()
{
    for(int i = 0; i < 6; i++)
    {
        switch(vecIn[i])
        {
        case Keys:
            Car_Keys = true;
            break;
        case Canister:
            Canister_of_gas = true;
            break;
        default:
            break;
        }
    }
}
void Player::addToInv(ObjectType type, int i, int j, int k)
{
    vecIn[k] = type;
    game->ticket->cards[game->geo_y][game->geo_x]->setPixmap(game->ticket->animCard[Air][0]);
    game->ticket->cardMap[game->geo_y][game->geo_x] = GameObject::None;
    game->ticket->cardMap[i][j] = type;
    game->map[game->geo_y][game->geo_x] = game->map[0][0];
    game->ticket->cards[game->geo_y][game->geo_x] = game->ticket->cards[0][0];
    game->ticket->cards[i][j]->setPixmap(game->ticket->animInv[type][0]);
}
void Player::moveup()
{
    setPixmap(anim[Up][0]);
    setY(static_cast<int>(y()) - 32);
}

void Player::moveleft()
{
    setPixmap(anim[Left][0]);
    setX(static_cast<int>(x()) - 32);
}

void Player::movedown()
{
    setPixmap(anim[Down][0]);
    setY(static_cast<int>(y()) + 32);
}
void Player::moveright()
{
    setPixmap(anim[Right][0]);
    setX(static_cast<int>(x()) + 32);
}
bool Player::overlapable(int i, int j)
{
    if(i < 1 || j < 1)
    {
        return false;
    }
    if(i > game->map_height - 2 || j > game->map_width - 2)
    {
        return false;
    }
    switch(game->map[i][j]->get_type())
    {
    case Wall:
        return false;
    case Door:
        return true;
    case Air:
        return true;
    case Winplace:
        cheakToWin();
        if(game->map[i][j]->get_type() == Winplace && Car_Keys == true && Canister_of_gas == true)
        {
            game->stat = Game::Win;
        }
        return true;
    case Ticket:
        if(game->ticket->cardMap[i][j] != GameObject::Air)
        {
            //game->ticket->cards[i][j]->setAnimTicket(i, j);
            if(game->ticket->cardMap[i][j] != GameObject::Zombie && game->ticket->cardMap[i][j] != GameObject::None)
            {
                game->ticket->cards[i][j]->setAnimTicket(i, j);
                game->stat = Game::Question;
            }
            else if(game->ticket->cardMap[i][j] == GameObject::Zombie && game->ticket->cards[i][j]->status == Ticket::Hidden)
            {
                game->ticket->cards[i][j]->setAnimTicket(i, j);
                QVector<int> tempXY;
                tempXY.push_back(i);
                tempXY.push_back(j);
                game->vecZombie.push_back(tempXY);
                game->ticket->cards[i][j]->status = Ticket::Active;
                game->stat = Game::MiniGame;
            }
            else if(game->ticket->cardMap[i][j] == GameObject::Zombie && game->ticket->cardMap[i][j] != GameObject::None)
            {
                game->stat = Game::MiniGame;
            }
        }
        return true;
    default:
        return true;
    }
}
void Player::player_move_up()
{
    int hero_x = static_cast<int>(x());
    int hero_y = static_cast<int>(y());
    int __x = (hero_x) / W;
    int __y = (hero_y) / W;
    if(overlapable(__y - 1, __x))
    {
        moveup();
        game->geo_x = __x;
        game->geo_y = __y - 1;
    }
}
void Player::player_move_down()
{
    int hero_x = static_cast<int>(x());
    int hero_y = static_cast<int>(y());
    int __x = (hero_x) / W;
    int __y = (hero_y) / W;

    if(overlapable(__y + 1, __x))
    {
        movedown();
        game->geo_x = __x;
        game->geo_y = __y + 1;
    }
}
void Player::player_move_left()
{
    int hero_x = static_cast<int>(x());
    int hero_y = static_cast<int>(y());
    int __x = (hero_x) / W;
    int __y = (hero_y) / W;
    if((hero_x) % W == 0 && overlapable(__y, __x - 1))
    {
        moveleft();
        game->geo_x = __x - 1;
        game->geo_y = __y;
    }
}
void Player::player_move_right()
{
    int hero_x = static_cast<int>(x());
    int hero_y = static_cast<int>(y());
    int __x = (hero_x) / W;
    int __y = (hero_y) / W;
    if((hero_x) % W == 0 && overlapable(__y, __x + 1))
    {
        moveright();
        game->geo_x = __x + 1;
        game->geo_y = __y;
    }
}
