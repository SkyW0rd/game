#include "game.h"
#define W (GameObject::Width)
Ticket::Ticket(ObjectType type) : GameObject(GameObject::Ticket, (type == GameObject::Gun) ? QPixmap(":/image/inventory.png") :
                                                                                             ((type == GameObject::Heart) ? QPixmap(":/image/heart.png") : QPixmap(":/image/surprise.png")))
{
    animCard[Heal].push_back(QPixmap(":/image/firstAidKit.png"));
    animCard[Knife].push_back(QPixmap(":/image/knife.png"));
    animCard[Pistol].push_back(QPixmap(":/image/weapon.png"));
    animCard[Keys].push_back(QPixmap(":/image/key.png"));
    animCard[Canister].push_back(QPixmap(":/image/canister.png"));
    animCard[Air].push_back(QPixmap(":/image/Air.png"));
    animCard[Zombie].push_back(QPixmap(":/image/zombie.png"));
    animInv[Heal].push_back(QPixmap(":/image/firstAidKitInv.png"));
    animInv[Knife].push_back(QPixmap(":/image/knifeInv.png"));
    animInv[Keys].push_back(QPixmap(":/image/keyInv.png"));
    animInv[Canister].push_back(QPixmap(":/image/canisterInv.png"));
    animInv[Pistol].push_back(QPixmap(":/image/weaponInv.png"));
    animInv[Gun].push_back(QPixmap(":/image/inventory.png"));
    animHeart.push_back(QPixmap(":/image/heart.png"));
    animHeart.push_back(QPixmap(":/image/heart1.png"));

    status = Hidden;
    animZombie[Up].push_back(QPixmap(":/image/zombie"));
    animZombie[Down].push_back(QPixmap(":/image/zombie"));
    animZombie[Left].push_back(QPixmap(":/image/zombie"));
    animZombie[Right].push_back(QPixmap(":/image/zombie"));



}


void Ticket::moveUp()
{
    setPixmap(animZombie[Up][0]);
    setY(static_cast<int>(y()) - 32);
    if(_x == game->geo_x && game->geo_y == _y - 1)
    {
        game->stat = Game::MiniGame;
    }
}
void Ticket::moveDown()
{
    setPixmap(animZombie[Down][0]);
    setY(static_cast<int>(y()) + 32);
    if(_x == game->geo_x && game->geo_y == _y + 1)
    {
        game->stat = Game::MiniGame;
    }
}
void Ticket::moveLeft()
{
    setPixmap(animZombie[Left][0]);
    setX(static_cast<int>(x()) - 32);
    if(_x - 1 == game->geo_x && game->geo_y == _y)
    {
        game->stat = Game::MiniGame;
    }
}
void Ticket::moveRight()
{
    setPixmap(animZombie[Right][0]);
    setX(static_cast<int>(x()) + 32);
    if(_x + 1 == game->geo_x && game->geo_y == _y)
    {
        game->stat = Game::MiniGame;
    }
}
void Ticket::chase_player()
{
    bool okdir[5] = {false, false, false, false, false};
    QVector<Dir> oklist;
    if (overlapable(_y, _x + 1))
    {
        okdir[Right] = true;
        oklist.push_back(Right);
    }
    if (overlapable(_y, _x - 1))
    {
        okdir[Left] = true;
        oklist.push_back(Left);
    }
    if (overlapable(_y + 1, _x))
    {
        okdir[Down] = true;
        oklist.push_back(Down);
    }
    if (overlapable(_y - 1, _x))
    {
        okdir[Up] = true;
        oklist.push_back(Up);
    }
    if(!overlapable(_y, _x))
    {
        okdir[Stop] = true;
        oklist.push_back(Stop);
    }

    Dir backward_dir;
    switch(dir)
    {
        case Up:
            backward_dir = Down;
            break;
        case Down:
            backward_dir = Up;
            break;
        case Left:
            backward_dir = Right;
            break;
        case Right:
            backward_dir = Left;
            break;
        case Stop:
            backward_dir = Stop;
            break;
    }
    if(oklist.size() > 2)
    {
        int dist_x = game->geo_x - _x;
        int dist_y = game->geo_y - _y;
        if(dist_y > 0)
        {
            if(okdir[Down] && dir != Up)
            {
                dir = Down;
            }
            else
            {
                if(dist_x >= 0)
                {
                    if(okdir[Right])
                    {
                        dir = Right;
                    }
                    else if(okdir[Left])
                    {
                        dir = Left;
                    }
                }
                else
                {
                    if (okdir[Left])
                    {
                        dir = Left;
                    }
                    else if (okdir[Right])
                    {
                        dir = Right;
                    }
                }
            }
        }
        else if (dist_y < 0)
        {
            if (okdir[Up] && dir != Down)
            {
                dir = Up;
            }
            else
            {
                if (dist_x >= 0)
                {
                    if (okdir[Right])
                    {
                        dir = Right;
                    }
                    else if (okdir[Left])
                    {
                        dir = Left;
                    }
                }
                else
                {
                    if (okdir[Left])
                    {
                        dir = Left;
                    }
                    else if (okdir[Right])
                    {
                        dir = Right;
                    }
                }
            }
        } else if (dist_x > 0)
        {
            if (okdir[Right] && dir != Left)
            {
                dir = Right;
            }
            else
            {
                if (okdir[Up])
                {
                    dir = Up;
                }
                else if(okdir[Down])
                {
                    dir = Down;
                }
            }
        }
        else if (dist_x < 0)
        {
            if (okdir[Left] && dir != Right)
            {
                dir = Left;
            }
            else
            {
                if (okdir[Up])
                {
                    dir = Up;
                }
                else if(okdir[Down])
                {
                    dir = Down;
                }
            }
        }
    }
    else if(oklist.size() == 2)
    {
        if(okdir[dir] == false)
        {
            if(oklist[0] == backward_dir)
            {
                dir = oklist[1];
            }
            else
            {
                dir = oklist[0];
            }
        }
    }
}
void Ticket::move(int n)
{
    int __x = game->vecZombie[n][1];
    int __y = game->vecZombie[n][0];
    if(game->ticket->cards[__y][__x]->status == Status::Active)
    {
        _y = __y;
        _x = __x;
        setDir_random();
        chase_player();
        switch(dir)
        {
            case Stop:
                break;
            case Up:
                moveUp();
                std::swap(game->ticket->cardMap[_y - 1][_x], game->ticket->cardMap[_y][_x]);
                std::swap(game->map[_y][_x], game->map[_y - 1][_x]);
                std::swap(game->ticket->cards[_y][_x], game->ticket->cards[_y - 1][_x]);
                game->vecZombie[n][0] = _y - 1;
                game->vecZombie[n][1] = _x;
                break;
            case Down:
                moveDown();
                std::swap(game->ticket->cardMap[_y + 1][_x], game->ticket->cardMap[_y][_x]);
                std::swap(game->map[_y][_x], game->map[_y + 1][_x]);
                std::swap(game->ticket->cards[_y][_x], game->ticket->cards[_y + 1][_x]);
                game->vecZombie[n][0] = _y + 1;
                game->vecZombie[n][1] = _x;
                break;
            case Left:
                moveLeft();
                std::swap(game->ticket->cardMap[_y][_x - 1], game->ticket->cardMap[_y][_x]);
                std::swap(game->map[_y][_x], game->map[_y][_x - 1]);
                std::swap(game->ticket->cards[_y][_x], game->ticket->cards[_y][_x - 1]);
                game->vecZombie[n][0] = _y;
                game->vecZombie[n][1] = _x - 1;
                break;
            case Right:
                moveRight();
                std::swap(game->ticket->cardMap[_y][_x + 1], game->ticket->cardMap[_y][_x]);
                std::swap(game->map[_y][_x], game->map[_y][_x + 1]);
                std::swap(game->ticket->cards[_y][_x], game->ticket->cards[_y][_x + 1]);
                game->vecZombie[n][0] = _y;
                game->vecZombie[n][1] = _x + 1;
                break;

        }
    }
}

bool Ticket::overlapable(int i,int j)
{
    if(i < 1 || j < 1)
    {
        return false;
    }
    if(i > game->map_height - 2 || j > game->map_width - 2)
    {
        return false;
    }
    switch (game->map[i][j]->get_type())
    {
    case Air:
        return true;
    /*case Wall:
        return false;
    case GameObject::Ticket:
        return false;
    case Winplace:
        return false;
    default:
        return true;*/
    default:
        return false;
    }
}

void Ticket::setDir_random()
{
    QVector<Dir> oklist;
    if (overlapable(_y, _x + 1))
    {
        oklist.push_back(Right);
    }
    if (overlapable(_y, _x - 1))
    {
        oklist.push_back(Left);
    }
    if (overlapable(_y + 1, _x))
    {
        oklist.push_back(Down);
    }
    if (overlapable(_y - 1, _x))
    {
        oklist.push_back(Up);
    }
    if (!overlapable(_y, _x))
    {
        oklist.push_back(Stop);
    }
    dir = oklist.at(QRandomGenerator::global()->generate() % oklist.size());
}
GameObject::ObjectType Ticket::noneTicket()
{
    return None;
}
GameObject::ObjectType Ticket::randTicket()
{
    ObjectType tempType = None;
    int high = 8, low = 0;
    while(tempType == None)
    {
        int rand = (qrand() % ((high + 1) - low) + low);
        if(winItems.size() != 0)
        {
            tempType = winItems[winItems.size() - 1];
            winItems.pop_back();
        }
        else if(firstAidKit.size() != 0)
        {
            tempType = firstAidKit[firstAidKit.size() - 1];
            firstAidKit.pop_back();
        }
        else if(guns.size() != 0)
        {
            tempType = guns[guns.size() - 1];
            guns.pop_back();
        }
        else if(zombies.size() != 0)
        {
            tempType = zombies[zombies.size() - 1];
            zombies.pop_back();
        }
        /*switch(rand)
        {
            case 0:
                if(winItems.size() != 0)
                {
                    tempType = winItems[winItems.size() - 1];
                    winItems.pop_back();
                }
                break;
            case 1:
                if(firstAidKit.size() != 0)
                {
                    tempType = firstAidKit[firstAidKit.size() - 1];
                    firstAidKit.pop_back();
                }
                break;
             case 2:
                if(guns.size() != 0)
                {
                    tempType = guns[guns.size() - 1];
                    guns.pop_back();
                }
                break;
            default:
                if(zombies.size() != 0)
                {
                    tempType = zombies[zombies.size() - 1];
                    zombies.pop_back();
                }
                break;
        }*/
    }
    return tempType;
}
void Ticket::setAnimTicket(int i, int j)
{
    switch(game->ticket->cardMap[i][j])
    {
        case Knife:
            game->ticket->cardMap[i][j] = GameObject::Knife;
            game->map[i][j]->setPixmap(animCard[Knife][0]);
            break;
        case Pistol:
            game->ticket->cardMap[i][j] = GameObject::Pistol;
            game->map[i][j]->setPixmap(animCard[Pistol][0]);
            break;
        case Heal:
            game->ticket->cardMap[i][j] = GameObject::Heal;
            game->map[i][j]->setPixmap(animCard[Heal][0]);
            break;
        case Keys:
            game->ticket->cardMap[i][j] = GameObject::Keys;
            game->map[i][j]->setPixmap(animCard[Keys][0]);
            break;
        case Canister:
            game->ticket->cardMap[i][j] = GameObject::Canister;
            game->map[i][j]->setPixmap(animCard[Canister][0]);
            break;
        case Zombie:
            game->ticket->cardMap[i][j] = GameObject::Zombie;
            game->map[i][j]->setPixmap(animCard[Zombie][0]);
            break;
        default:
            break;
    }
}
