#include "knight2.h"

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }

    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void BaseKnight::setKnightType(int hpget)
{
    if (isPrime(hpget))
    {
        knightType = PALADIN;
        return;
    }

    else if (hpget == 888)
    {
        knightType = LANCELOT;
        return;
    }

    else
    {
        int temp = hpget;
        int z = temp % 10;
        temp = temp / 10;
        int y = temp % 10;
        temp = temp / 10;
        int x = temp % 10;

        if ((hpget >= 100 && hpget <= 999) && (x * x + y * y == z * z || z * z + y * y == x * x || x * x + z * z == y * y))
        {
            knightType = DRAGON;
            return;
        }

        else
        {
            knightType = NORMAL;
            return;
        }
    }
}

/* * * BEGIN implementation of class BaseBag * * */

BaseBag::BaseBag()
{
    sizeBag = 0;
    head = nullptr;
}

bool BaseBag::insertFirst(BaseItem *item)
{
    if (maxSize == -1 || sizeBag < maxSize)
    {
        if (maxSize == maxDragonBag && item->itemType == Antidote)
        {
            if (knight -> getId() > 0)
            {
                BaseKnight * beforeKnight = knight - 1;
                beforeKnight -> getBag() -> insertFirst(item);
            }

            else if (knight -> getId() == 0)
            {
                return false;
            }    
        }

        item->next = head;
        head = item;
        sizeBag += 1;
        return true;
    }
    return false;
}

string BaseBag::toString() const
{
    if (sizeBag == 0)
    {
        return "Bag[count=0]";
    }
    string s("");
    int arr[sizeBag];
    BaseItem *temp = head;
    int iter = 0;
    while (temp != nullptr)
    {
        arr[iter] = temp->itemType;

        temp = temp->next;
        iter += 1;
    }
    
    s += "Bag[count=" + to_string(sizeBag) + ";";
    for (int i = 0; i < sizeBag; i++)
    {
        if (arr[i] == phoenixDownI)
        {
            s += "PhoenixI"; 
        } 
        else if (arr[i] == phoenixDownII)
        {
            s += "PhoenixII"; 
        } 
        else if (arr[i] == phoenixDownIII)
        {
            s += "PhoenixIII"; 
        } 
        else if (arr[i] == phoenixDownIV)
        {
            s += "PhoenixIV"; 
        } 
        else if (arr[i] == Antidote)
        {
            s += "Antidote"; 
        } 
        if (i + 1 != sizeBag)
        {
            s+= ",";
        }
    }
    s += "]";
    return s;
}

void BaseBag::insertBag(ItemType item)
{
    if (item == phoenixDownI)
    {
        classPhoenixI *object = new classPhoenixI();
        object->next = head;
        head = object;
        sizeBag += 1;
    }
    else if (item == phoenixDownII)
    {
        classPhoenixII *object = new classPhoenixII();
        object->next = head;
        head = object;
        sizeBag += 1;
    }
    else if (item == phoenixDownIII)
    {
        classPhoenixIII *object = new classPhoenixIII();
        object->next = head;
        head = object;
        sizeBag += 1;
    }
    else if (item == phoenixDownIV)
    {
        classPhoenixIV *object = new classPhoenixIV();
        object->next = head;
        head = object;
        sizeBag += 1;
    }
    else
    {
        classAntidote *object = new classAntidote();
        object->next = head;
        head = object;
        sizeBag += 1;
    }
}

BaseItem *BaseBag::get(ItemType itemType)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (itemType == FirstPhoenixDown)
    {
        BaseItem *temp = head;
        while (temp != nullptr)
        {
            if (temp->itemType == phoenixDownI || temp->itemType == phoenixDownII ||temp->itemType == phoenixDownIII ||temp->itemType == phoenixDownIV)
            {
                return temp;
                // ItemType temp2;
                // temp2 = temp->itemType;
                // temp->itemType = head->itemType;
                // head->itemType = temp2;
                // temp = nullptr;
                // delete temp;
                // return head;
            }
            temp = temp -> next;
        }
        return nullptr;
    }

    BaseItem *temp = head;
    while (temp != nullptr)
    {
        if (temp->itemType == itemType)
        {
            return temp;
        //     ItemType temp2;
        //     temp2 = temp->itemType;
        //     temp->itemType = head->itemType;
        //     head->itemType = temp2;
        //     temp = nullptr;
        //     delete temp;
        //     return head;
        }
        temp = temp -> next;
    }
    return nullptr;
}

void BaseBag::swapBag(BaseItem *item)
{
    if (item == nullptr)
    {
        return;
    }
    ItemType temp = item->itemType;
    item->itemType = head->itemType;
    head->itemType = temp;
}

void BaseBag::deleteBag()
{
    if (head == nullptr)
    {
        return;
    }
    BaseItem * temp = head;
    head = head -> next;
    delete temp;
}

/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseKnight * * */

BaseKnight::BaseKnight()
{
    bag = new BaseBag();
}

// void BaseKnight::print()
// {
//     cout << id << " " << hp << " " << maxhp << " " << level << " " << gil << " " << antidote << " " << phoenixdownI << endl;
// }

// void BaseKnight::printlist()
// {
//     BaseItem *temp = bag->head;
//     while (temp != nullptr)
//     {
//         cout << temp->itemType << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

static BaseKnight *create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
{
    BaseKnight *newKnight = new BaseKnight();
    newKnight->setId(id);
    newKnight->setHp(maxhp);
    newKnight->setMaxhp(maxhp);
    newKnight->setLevel(level);
    newKnight->setGil(gil);
    newKnight->setAntidote(antidote);
    newKnight->setPhoenixdownI(phoenixdownI);
    newKnight->setBag(Antidote, antidote);
    newKnight->setBag(phoenixDownI, phoenixdownI);
    newKnight -> getBag() -> knight = newKnight; 
    newKnight -> setKnightType(maxhp);

    return newKnight;
}

string BaseKnight::toString() const
{
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id) + ",hp:" + to_string(hp) + ",maxhp:" + to_string(maxhp) + ",level:" + to_string(level) + ",gil:" + to_string(gil) + "," + bag->toString() + ",knight_type:" + typeString[knightType] + "]";
    return s;
}

void BaseKnight::setBag(ItemType item, int size)
{    
    if (size >= 1)
    {
        if (size >= 5)
        {
            size = 5;
        }

        for (int i = 0; i < size; i++)
        {
            if (item == phoenixDownI)
            {
                bag->insertBag(item);
            }

            else if (item == phoenixDownII)
            {
                bag->insertBag(item);
            }

            else if (item == phoenixDownIII)
            {
                bag->insertBag(item);
            }

            else if (item == phoenixDownIV)
            {
                bag->insertBag(item);
            }

            else if (item == Antidote)
            {
                bag->insertBag(item);
            }  
        }
    }
    // else
    // {
    //     bag = nullptr;
    // }
}

/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */

ArmyKnights::ArmyKnights(const string &file_armyknights)
{    
    PaladinShield = false;
    LancelotSpear = false;
    GuinevereHair = false;
    ExcaliburSword = false;

    ifstream fp;
    fp.open(file_armyknights);
    fp >> sizeArmy;
    arrArmy = new BaseKnight[sizeArmy];
    int hp, level, phoenixdownI, gil, antidote;
    for (int i = 0; i < sizeArmy; i++)
    {
        fp >> hp >> level >> phoenixdownI >> gil >> antidote;
        arrArmy[i] = *create(i + 1, hp, level, gil, antidote, phoenixdownI);
    }
    fp.close();
}

ArmyKnights::~ArmyKnights()
{
    delete[] arrArmy;
}

BaseKnight * ArmyKnights::lastKnight() const 
{
    if (sizeArmy == 0)
    {
        return nullptr;
    }

    BaseKnight * lastKnight = &arrArmy[(this -> sizeArmy) - 1]; 
    return lastKnight;
}

bool ArmyKnights::fight(BaseOpponent * opponent)
{
    BaseKnight * lastKnight = this -> lastKnight();

    int levelOppo = opponent -> levelO;
    int baseDam = opponent -> baseDamage;
    int evenNum =  opponent->eventNum;

    int gil = lastKnight -> getGil();
    int level = lastKnight -> getLevel();
    int hp = lastKnight -> getHp();
    int maxhp = lastKnight -> getMaxhp();
    int typ = lastKnight->getKnightType();

    if (evenNum >= 1 && evenNum <= 5)
    {
        if (level >= levelOppo || typ == LANCELOT || typ == PALADIN)
        {
            gil += opponent->gilIfWin;
            if (gil > 999)
            {
                gil = 999;
            }
            lastKnight -> setGil(gil);
            return true;
        }

        hp = hp - baseDam * (levelOppo - level);
        lastKnight -> setHp(hp);
        if (hp <= 0)
        {
            if (lastKnight->getBag()->get(FirstPhoenixDown) != nullptr)
            {
                lastKnight->getBag()->swapBag(lastKnight->getBag()->get(FirstPhoenixDown));
                lastKnight->getBag()->get(FirstPhoenixDown)->use(lastKnight);
                return true;
            }

            if (gil >= 100)
            {
                gil -= 100;
                hp = maxhp / 2;
                return true;
            }

            delete lastKnight;
            sizeArmy -= 1;
            return false;
        }
        return true;
    }
    
    else if (evenNum == 6)
    {
        if (level >= levelOppo)
        {
            level += 1;
            if (level >= 10)
            {
                level = 10;
            }
            lastKnight -> setLevel(level);
            return true;
        }  

        if (typ == DRAGON)
        {
            return true;
        }

        if (lastKnight->getBag()->get(Antidote) != nullptr)
        {
            lastKnight->getBag()->swapBag(lastKnight->getBag()->get(Antidote));
            lastKnight->getBag()->get(Antidote)->use(lastKnight);
            return true;
        }

        //thua o day ne
        BaseItem * temp = lastKnight->getBag()->head;
        if (lastKnight->getBag()->sizeBag <= 3)
        {
            lastKnight->getBag()->head = NULL;
            while (temp != NULL)
            {
                BaseItem * nest = temp -> next;
                delete temp;
                temp = nest;
            }
            lastKnight->getBag()->sizeBag = 0;
        }

        else 
        {
            for (int i = 0; i < lastKnight->getBag()->sizeBag - 3; i++) 
            {
                temp = temp->next;
            }

            while (temp != NULL)
            {
                BaseItem * nest = temp -> next;
                delete temp;
                temp = nest;
            }
            lastKnight->getBag()->sizeBag -= 3;
        }

        hp -= 10;
        lastKnight -> setHp(hp);
        if (hp <= 0)
        {
            if (lastKnight->getBag()->get(FirstPhoenixDown) != nullptr)
            {
                lastKnight->getBag()->swapBag(lastKnight->getBag()->get(FirstPhoenixDown));
                lastKnight->getBag()->get(FirstPhoenixDown)->use(lastKnight);
                return true;
            }

            if (gil >= 100)
            {
                gil -= 100;
                hp = maxhp / 2;
                return true;
            }

            delete lastKnight;
            sizeArmy -= 1;
            return false;
        } 
        return true;
    }
    
    else if (evenNum == 7)
    {
        if (level >= levelOppo)
        {
            gil *= 2;
            if (gil > 999)
            {
                gil = 999;
            }
            lastKnight -> setGil(gil);
            return true;
        } 
    }
    //TO DO 

    cout << "no chay di dau ne" << endl;
    return false;
}

/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class Events * * */
Events::Events(const string &file_events)
{
    ifstream fp;
    fp.open(file_events);
    fp >> sizeEvents;
    arrEvents = new int[sizeEvents];
    int event;
    for (int i = 0; i < sizeEvents; i++)
    {
        fp >> event;
        arrEvents[i] = event;
    }
    fp.close();
}

Events::~Events()
{
    delete[] arrEvents;
}

/* * * END implementation of class Events * * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure()
{
    armyKnights = nullptr;
    events = nullptr;
}

KnightAdventure::~KnightAdventure()
{
    delete armyKnights;
    delete events;
}

void KnightAdventure::loadArmyKnights(const string &file_armyknights)
{
    armyKnights = new ArmyKnights(file_armyknights);
}

void KnightAdventure::loadEvents(const string &file_events)
{
    events = new Events(file_events);
}

void KnightAdventure::run()
{
    for (int i = 0; i < armyKnights->sizeArmy; i++)
    {
        cout << armyKnights->arrArmy[i].toString() << endl;
    }
    cout << "---------------------------------" <<endl;

    for (int i = 0; i < events->sizeEvents; i++)
    {
        int thisEvent = events->arrEvents[i];
        BaseKnight lastKnight = armyKnights->arrArmy[armyKnights->sizeArmy - 1];

        if (thisEvent >= 1 && thisEvent <= 5)
        {
            int levelO = (i + thisEvent) % 10 + 1;

            if (thisEvent == 1)
            {
                MadBear * opponent = new MadBear(levelO);
                armyKnights->fight(opponent);
            }
            if (thisEvent == 2)
            {
                Bandit * opponent = new Bandit(levelO);
                armyKnights->fight(opponent);
            }
            if (thisEvent == 3)
            {
                LordLupin * opponent = new LordLupin(levelO);
                armyKnights->fight(opponent);
            }
            if (thisEvent == 4)
            {
                Elf * opponent = new Elf(levelO);
                armyKnights->fight(opponent);
            }
            if (thisEvent == 5)
            {
                Troll * opponent = new Troll(levelO);
                armyKnights->fight(opponent);
            }
        }

        else if (thisEvent == 6)
        {
            int levelO = (i + thisEvent) % 10 + 1;
            Tornbery * opponent = new Tornbery(levelO);
            armyKnights->fight(opponent);
        }

        else if (thisEvent == 7)
        {
            int levelO = (i + thisEvent) % 10 + 1;
            QueenOfCards * opponent = new QueenOfCards(levelO);
            armyKnights->fight(opponent);
        }


        else if (thisEvent == 95)
        {
            armyKnights->PaladinShield = true;
        }
        
        else if (thisEvent == 96)
        {
            armyKnights->LancelotSpear = true;
        }
        
        else if (thisEvent == 97)
        {
            armyKnights->GuinevereHair = true;
        }

        else if (thisEvent == 98)
        {
            if (armyKnights->PaladinShield == true && armyKnights->LancelotSpear == true && armyKnights->GuinevereHair == true)
            {
                armyKnights->ExcaliburSword == true;
            }
        }
        
        cout << "---------------------------------" <<endl;
        for (int i = 0; i < armyKnights->sizeArmy; i++)
        {
            cout << armyKnights->arrArmy[i].toString() << endl;
        }
    }

}

/* * * END implementation of class KnightAdventure * * */