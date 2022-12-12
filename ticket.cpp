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
}
void Ticket::anim()
{

}
void Ticket::healAction()
{

}
GameObject::ObjectType Ticket::noneTicket()
{
    return None;
}
GameObject::ObjectType Ticket::randTicket()
{
    ObjectType tempType = None;
    int high = 10, low = 0;
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
