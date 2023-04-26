#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG

enum ItemType { ANTIDOTE = 0, PHOENIXDOWN_I, PHOENIXDOWN_II, PHOENIXDOWN_III, PHOENIXDOWN_IV };

class BaseKnight;

class BaseItem {
public:
    virtual bool canUse(BaseKnight* knight);
    virtual void use(BaseKnight* knight);
    ItemType itemType;
};

class BaseBag {
protected:
    int maxSize;
    int size;
    struct Node {
        BaseItem* item;
        Node* next;
        Node(BaseItem* item) : item(item), next(nullptr) {}
    };
    Node* head;
    BaseKnight* knight;
public:
    BaseBag(BaseKnight* knight, int maxSize) : head(nullptr), knight(knight) {}
    virtual ~BaseBag();
    virtual bool insertFirst(BaseItem* item);
    virtual BaseItem* get(ItemType itemType);
    virtual string toString() const = 0;
};

enum OpponentType { MBear = 0, Bdit, Lupin, ELF, TROLL, Tbery, QCards, NRings, DGarden, OWeapon, HADES };

class BaseOpponent{
protected:
    OpponentType opponentType;
public:
    int level;
    int dmg;
    int gil;
    static BaseOpponent * create(int level, int dmg, int gil, OpponentType opponentType);
    virtual ~BaseOpponent() {};
};

class MadBear : public BaseOpponent {
public:
    MadBear(int level, int dmg, int gil, OpponentType opponentType)
    {
        this->level = level;
        this->dmg = 10;
        this->gil = gil;
        this->opponentType = opponentType;
    }
};

class Bandit : public BaseOpponent {
public:
    Bandit(int level, int dmg, int gil, OpponentType opponentType)
    {
        this->level = level;
        this->dmg = 15;
        this->gil = gil;
        this->opponentType = opponentType;
    }
};

class LordLupin : public BaseOpponent {
public:
    LordLupin(int level, int dmg, int gil, OpponentType opponentType)
    {
        this->level = level;
        this->dmg = 45;
        this->gil = gil;
        this->opponentType = opponentType;
    }
};

class Elf : public BaseOpponent {
public:
    Elf(int level, int dmg, int gil, OpponentType opponentType)
    {
        this->level = level;
        this->dmg = 75;
        this->gil = gil;
        this->opponentType = opponentType;
    }
};

class Troll : public BaseOpponent {
public:
    Troll(int level, int dmg, int gil, OpponentType opponentType)
    {
        this->level = level;
        this->dmg = 95;
        this->gil = gil;
        this->opponentType = opponentType;
    }
};

class Tornbery : public BaseOpponent {
public:
    Tornbery(int level, int dmg, int gil, OpponentType opponentType)
    {
        this->level = level;
        this->dmg = dmg;
        this->gil = gil;
        this->opponentType = opponentType;
    }
};

class QueenOfCards : public BaseOpponent {
public:
    QueenOfCards(int level, int dmg, int gil, OpponentType opponentType)
    {
        this->level = level;
        this->dmg = dmg;
        this->gil = gil;
        this->opponentType = opponentType;
    }
};

class NinaDeRings : public BaseOpponent {
public:
    NinaDeRings(int level, int dmg, int gil, OpponentType opponentType)
    {
        this->level = level;
        this->dmg = dmg;
        this->gil = gil;
        this->opponentType = opponentType;
    }
};

class DurianGarden : public BaseOpponent {
public:
    DurianGarden(int level, int dmg, int gil, OpponentType opponentType)
    {
        this->level = level;
        this->dmg = dmg;
        this->gil = gil;
        this->opponentType = opponentType;
    }
};

class OmegaWeapon : public BaseOpponent {
public:
    OmegaWeapon(int level, int dmg, int gil, OpponentType opponentType)
    {
        this->level = level;
        this->dmg = dmg;
        this->gil = gil;
        this->opponentType = opponentType;
    }
};

class Hades : public BaseOpponent {
public:
    Hades(int level, int dmg, int gil, OpponentType opponentType)
    {
        this->level = level;
        this->dmg = dmg;
        this->gil = gil;
        this->opponentType = opponentType;
    }
};

enum KnightType { PALADIN = 0, LANCELOT, DRAGON, NORMAL };

class BaseKnight {
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    double baseDmg;
    int gil;
    int antidote;
    int phoenixdownI;
    BaseBag * bag;
    KnightType knightType;
public:
    static BaseKnight * create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;
    virtual void fight(BaseOpponent * opponent);
    int getCurrentHP() const { return hp; }
    int getMaxHP() const { return maxhp; }
    void restoreHP(int amount) { hp = min(maxhp, hp + amount); }
    bool isPoisoned = false;
    void curePoison() { isPoisoned = false; }
    KnightType getKnightType() { return knightType; }
    virtual ~BaseKnight() {};
};

class Paladin : public BaseKnight {
public:
    Paladin(int id, int hp, int level, int gil, int antidote, int phoenixdownI)
    {
        this->id = id;
        this->hp = hp;
        this->maxhp = this->hp;
        this->level = level;
        this->baseDmg = 0.06;
        this->gil = gil;
        this->antidote = antidote;
        this->phoenixdownI = phoenixdownI;
        this->knightType = PALADIN;
    }
    void fight(BaseOpponent* opponent) override {
        // implement fight method for PaladinKnight
        return BaseKnight::fight(opponent);
    }
};

class Lancelot : public BaseKnight {
public:
    Lancelot(int id, int hp, int level, int gil, int antidote, int phoenixdownI)
    {
        this->id = id;
        this->hp = hp;
        this->maxhp = this->hp;
        this->level = level;
        this->baseDmg = 0.05;
        this->gil = gil;
        this->antidote = antidote;
        this->phoenixdownI = phoenixdownI;
        this->knightType = LANCELOT;
    }

    void fight(BaseOpponent* opponent) override {
        // implement fight method for LancelotKnight
        return BaseKnight::fight(opponent);
    }
};

class DragonKnight : public BaseKnight {
public:
    DragonKnight(int id, int hp, int level, int gil, int antidote, int phoenixdownI)
    {
        this->id = id;
        this->hp = hp;
        this->maxhp = this->hp;
        this->level = level;
        this->baseDmg = 0.075;
        this->gil = gil;
        this->antidote = antidote;
        this->phoenixdownI = phoenixdownI;
        this->knightType = DRAGON;
    }

    void fight(BaseOpponent* opponent) override {
        // implement fight method for DragonKnight
        return BaseKnight::fight(opponent);
    }
};

class NormalKnight : public BaseKnight {
public:
    NormalKnight(int id, int hp, int level, int gil, int antidote, int phoenixdownI)
    {
        this->id = id;
        this->hp = hp;
        this->maxhp = this->hp;
        this->level = level;
        this->gil = gil;
        this->antidote = antidote;
        this->phoenixdownI = phoenixdownI;
        this->knightType = NORMAL;
    }

    void fight(BaseOpponent* opponent) override {
        // implement fight method for NormalKnight
        return BaseKnight::fight(opponent);
    }
};

class Events {
public:
    Events(const string & file_events);
    ~Events();
    int count() const;
    int get(int i) const;
protected:
    int* event_codes;
    int num_events;
};

class ArmyKnights {
private:    
    BaseKnight * knights[1000];
    int count_;
public:
    ArmyKnights (const string & file_armyknights);
    ~ArmyKnights();
    bool fight(BaseOpponent * opponent);
    bool adventure (Events * events);
    int count() const;
    BaseKnight* lastKnight() const;

    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;

    void printInfo() const;
    void printResult(bool win) const;
};

class KnightAdventure {
private:
    ArmyKnights * armyKnights;
    Events * events;
public:
    KnightAdventure();
    ~KnightAdventure();

    void loadArmyKnights(const string & filename){
        if (armyKnights != nullptr) {
            delete armyKnights;
        }
        armyKnights = new ArmyKnights(filename);
        };

    void loadEvents(const string & filename){
        if (events != nullptr) {
            delete events;
        }
        events = new Events(filename);
    };
    void run();
};

#endif // __KNIGHT2_H__