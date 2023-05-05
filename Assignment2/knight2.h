#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

#define maxDragonBag 14
#define maxLancelotBag 16
#define maxNormalBag 19

enum ItemType
{
    phoenixDownI = 0,
    phoenixDownII,
    phoenixDownIII,
    phoenixDownIV,
    Antidote,
    FirstPhoenixDown
};

class BaseItem;

class BaseKnight;

class BaseBag
{
public:
    BaseKnight *knight;
    BaseItem *head;
    int sizeBag;
    int maxSize;
    BaseBag();

    void insertBag(ItemType item);
    void swapBag(BaseItem *item);
    void deleteBag();

    // void print();
    // void printlist();
    virtual bool insertFirst(BaseItem *item); 
    virtual BaseItem *get(ItemType itemType);
    virtual string toString() const; //have to
    // virtual ~BaseBag() {}
};

enum KnightType
{
    PALADIN = 0,
    LANCELOT,
    DRAGON,
    NORMAL
};

class BaseKnight
{
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    int antidote;
    int phoenixdownI;
    BaseBag *bag;
    KnightType knightType;

public:
    BaseKnight();
    ~BaseKnight()
    {
        delete bag;
    }

    void print();
    void printlist();

    int getId() { return id; }
    void setId(int id1) { id = id1; }

    int getHp() { return hp; }
    void setHp(int hp1) { hp = hp1; }

    int getMaxhp() { return maxhp; }
    void setMaxhp(int maxhp1) { maxhp = maxhp1; }

    int getLevel() { return level; }
    void setLevel(int level1) { level = level1; }

    int getGil() { return gil; }
    void setGil(int gil1) { gil = gil1; }

    int getAntidote() { return antidote; }
    void setAntidote(int antidote1) { antidote = antidote1; }

    int getPhoenixdownI() { return phoenixdownI; }
    void setPhoenixdownI(int phoenixdownI1) { phoenixdownI = phoenixdownI1; }

    int getKnightType() { return knightType; }
    void setKnightType(int hpget);

    BaseBag *getBag() { return bag; }

    void setBag(ItemType item, int size);
    static BaseKnight *create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;
};

class DragonBag : public BaseBag
{
    DragonBag()
    {
        maxSize = maxDragonBag;
    }

    // bool insertFirst(BaseItem *item)
    // {
    //     return true;
    // }

    BaseItem *get(ItemType itemType)
    {
        BaseItem * haha = nullptr;
        return haha;
    }
    string toString() 
    {
        return "1";
    }
};

class LancelotBag : public BaseBag
{
    LancelotBag()
    {
        maxSize = maxLancelotBag;
    }

    // bool insertFirst(BaseItem *item)
    // {
    //     return true;
    // }
    BaseItem *get(ItemType itemType)
    {
        BaseItem * haha = nullptr;
        return haha;
    }
    string toString() 
    {
        return "1";
    }
};

class PaladinBag : public BaseBag
{
    PaladinBag()
    {
        maxSize = -1;
    }

    // bool insertFirst(BaseItem *item)
    // {
    //     return true;
    // }
    BaseItem *get(ItemType itemType)
    {
        BaseItem * haha = nullptr;
        return haha;
    }
    string toString() 
    {
        return "1";
    }
};

class NormalBag : public BaseBag
{
    NormalBag()
    {
        maxSize = maxNormalBag;
    }

    // bool insertFirst(BaseItem *item)
    // {
    //     return true;
    // }
    BaseItem *get(ItemType itemType)
    {
        BaseItem * haha = nullptr;
        return haha;
    }
    string toString() 
    {
        return "1";
    }
};

class BaseOpponent
{
public:
    int eventNum;
    int baseDamage;
    int gilIfWin;
    int levelO;
};

class MadBear: public BaseOpponent
{   
public:
    MadBear(int levelIn)
    {   
        eventNum = 1;
        baseDamage = 10;
        gilIfWin = 100;
        levelO = levelIn;
    }
};

class Bandit: public BaseOpponent
{
public:
    Bandit(int levelIn)
    {
        eventNum = 2;
        baseDamage = 15;
        gilIfWin = 150;
        levelO = levelIn;
    }
};

class LordLupin: public BaseOpponent
{
public:
    LordLupin(int levelIn)
    {
        eventNum = 3;
        baseDamage = 45;
        gilIfWin = 450;
        levelO = levelIn;
    }
};

class Elf: public BaseOpponent
{
public:
    Elf(int levelIn)
    {
        eventNum = 4;
        baseDamage = 75;
        gilIfWin = 750;
        levelO = levelIn;
    }
};

class Troll: public BaseOpponent
{
public:
    Troll(int levelIn)
    {
        eventNum = 5;
        baseDamage = 95;
        gilIfWin = 800;
        levelO = levelIn;
    }
};

class Tornbery: public BaseOpponent
{
public:
    Tornbery(int levelIn)
    {
        eventNum = 6;
        levelO = levelIn;
    }
};

class QueenOfCards: public BaseOpponent
{
public:
    QueenOfCards(int levelIn)
    {
        eventNum = 7;
        levelO = levelIn;
    }
};

class NinaDeRings:public BaseOpponent
{
public:
    NinaDeRings(int levelIn)
    {
        eventNum = 8;
    }
};

class DurianGarden:public BaseOpponent
{
public:
    DurianGarden(int levelIn)
    {
        eventNum = 9;
    }
};

class OmegaWeapon:public BaseOpponent
{
public:
    OmegaWeapon(int levelIn)
    {
        eventNum = 10;
    }
};

class Hades:public BaseOpponent
{
public:
    Hades(int levelIn)
    {
        eventNum = 11;
    }
};

class BaseItem
{
public:
    ItemType itemType;
    BaseItem *next;
    BaseItem()
    {
        next = nullptr;
    }
    virtual bool canUse(BaseKnight *knight) = 0;
    virtual void use(BaseKnight *knight) = 0;
};

class classPhoenixI : public BaseItem
{
public:
    classPhoenixI()
    {
        itemType = phoenixDownI;
        next = nullptr;
    }
    bool canUse(BaseKnight *knight)
    {
        int hp = knight->getHp();
        if (hp <= 0)
        {
            return true;
        }
        return false;
    }
    void use(BaseKnight *knight)
    {
        int hp = knight->getHp();
        int maxhp = knight->getMaxhp();
        hp = maxhp;
        knight->setHp(hp);
        knight->getBag()->deleteBag();
        knight->getBag()->sizeBag -= 1;
    }
};

class classPhoenixII : public BaseItem
{
public:
    classPhoenixII()
    {
        itemType = phoenixDownII;
        next = nullptr;
    }
    bool canUse(BaseKnight *knight)
    {
        int hp = knight->getHp();
        int maxhp = knight->getMaxhp();
        if (hp < maxhp / 4)
        {
            return true;
        }
        return false;
    }
    void use(BaseKnight *knight)
    {
        int hp = knight->getHp();
        int maxhp = knight->getMaxhp();
        hp = maxhp;
        knight->setHp(hp);
        knight->getBag()->deleteBag();
        knight->getBag()->sizeBag -= 1;
    }
};

class classPhoenixIII : public BaseItem
{
public:
    classPhoenixIII()
    {
        itemType = phoenixDownIII;
        next = nullptr;
    }
    bool canUse(BaseKnight *knight)
    {
        int hp = knight->getHp();
        int maxhp = knight->getMaxhp();
        if (hp < maxhp / 3)
        {
            return true;
        }
        return false;
    }
    void use(BaseKnight *knight)
    {
        int hp = knight->getHp();
        int maxhp = knight->getMaxhp();
        if (hp <= 0)
        {
            hp = maxhp / 3;
        }
        else
        {
            hp += maxhp / 4;
        }
        knight->setHp(hp);
        knight->getBag()->deleteBag();
        knight->getBag()->sizeBag -= 1;

    }
};

class classPhoenixIV : public BaseItem
{
public:
    classPhoenixIV()
    {
        itemType = phoenixDownIV;
        next = nullptr; 
    }
    bool canUse(BaseKnight *knight)
    {
        int hp = knight->getHp();
        int maxhp = knight->getMaxhp();
        if (hp < maxhp / 2)
        {
            return true;
        }
        return false;
    }
    void use(BaseKnight *knight)
    {
        int hp = knight->getHp();
        int maxhp = knight->getMaxhp();
        if (hp <= 0)
        {
            hp = maxhp / 2;
        }
        else
        {
            hp += maxhp / 5;
        }
        knight->setHp(hp);
        knight->getBag()->deleteBag();
        knight->getBag()->sizeBag -= 1;
    }
};

class classAntidote : public BaseItem
{
public:    
    classAntidote()
    {
        itemType = Antidote;
        next = nullptr;
    }
    bool canUse(BaseKnight *knight)
    {
        return true;
    }
    void use(BaseKnight *knight)
    {
        knight->getBag()->deleteBag();
        knight->getBag()->sizeBag -= 1;
    }
};

class Events;

class ArmyKnights
{
public:
    bool PaladinShield;
    bool LancelotSpear;
    bool GuinevereHair;
    bool ExcaliburSword;
    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;

    BaseKnight *arrArmy;
    int sizeArmy;

    ArmyKnights(const string &file_armyknights);
    ~ArmyKnights();
    bool fight(BaseOpponent *opponent);
    bool adventure(Events *events);
    int count() const;
    BaseKnight *lastKnight() const;
};

class Events
{
public:
    int *arrEvents;
    int sizeEvents;
    Events(const string &file_events);
    ~Events();

    int count() const;
    int get(int i) const;
};

class KnightAdventure
{
private:
    ArmyKnights *armyKnights;
    Events *events;

public:
    KnightAdventure();
    ~KnightAdventure();

    void loadArmyKnights(const string &);
    void loadEvents(const string &);
    void run();
};

#endif // __KNIGHT2_H__