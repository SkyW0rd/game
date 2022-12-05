#include "game.h"
#define W (GameObject::Width)

Player::Player() : GameObject(
    GameObject::Player, QPixmap("C:\\Users\\Zalman N3\\Desktop\\game\\game\\res\\image\\catFront.png"))
{
     dir = Stop;
     next_dir = Stop;
     anim_index = 0;
     anim[Right].push_back(QPixmap("C:\\Users\\Zalman N3\\Desktop\\game\\game\\res\\image\\catRight.png"));

     anim[Up].push_back(QPixmap("C:\\Users\\Zalman N3\\Desktop\\game\\game\\res\\image\\catBack.png"));

     anim[Left].push_back(QPixmap("C:\\Users\\Zalman N3\\Desktop\\game\\game\\res\\image\\catLeft.png"));

     anim[Down].push_back(QPixmap("C:\\Users\\Zalman N3\\Desktop\\game\\game\\res\\image\\catFront.png"));

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
    case Winplace:
        cheakToWin();
        if(game->map[i][j]->get_type() == Winplace && Car_Keys == true && Canister_of_gas == true)
        {
            game->stat = Game::Win;
        }
    default:
        return true;
    }
}
void Player::player_move_up()
{
    int hero_x = static_cast<int>(x());
    int hero_y = static_cast<int>(y());
    int __x = (hero_x - game->geo_x) / W;
    int __y = (hero_y - game->geo_y) / W;
    if(overlapable(__y - 1, __x))
    {
        moveup();
    }
}
void Player::player_move_down()
{
    int hero_x = static_cast<int>(x());
    int hero_y = static_cast<int>(y());
    int __x = (hero_x - game->geo_x) / W;
    int __y = (hero_y - game->geo_y) / W;

    if(overlapable(__y + 1, __x))
    {
        movedown();
    }
}
void Player::player_move_left()
{
    int hero_x = static_cast<int>(x());
    int hero_y = static_cast<int>(y());
    int __x = (hero_x - game->geo_x) / W;
    int __y = (hero_y - game->geo_y) / W;
    if((hero_x + game->geo_x) % W == 0 && overlapable(__y, __x - 1))
    {
        moveleft();
    }
}
void Player::player_move_right()
{
    int hero_x = static_cast<int>(x());
    int hero_y = static_cast<int>(y());
    int __x = (hero_x - game->geo_x) / W;
    int __y = (hero_y - game->geo_y) / W;
    if((hero_x + game->geo_x) % W == 0 && overlapable(__y, __x + 1))
    {
        moveright();
    }
}
