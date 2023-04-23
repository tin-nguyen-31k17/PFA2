#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG

enum ItemType { ANTIDOTE = 0, PHOENIXDOWN_I, PHOENIXDOWN_II, PHOENIXDOWN_III, PHOENIXDOWN_IV };

class BaseKnight;

class BaseItem {
public:
    virtual bool canUse(BaseKnight* knight) = 0;
    virtual void use(BaseKnight* knight) = 0;
    virtual ~BaseItem() {};
};

class Antidote : public BaseItem {
public:
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};

class PhoenixDownI : public BaseItem {
public:
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};

class PhoenixDownII : public BaseItem {
public:
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};

class PhoenixDownIII : public BaseItem {
public:
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};

class PhoenixDownIV : public BaseItem {
public:
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
};

class BaseBag {
public:
    virtual bool insertFirst(BaseItem* item) = 0;
    virtual BaseItem* get(ItemType itemType) = 0;
    virtual string toString() const = 0;
    virtual ~BaseBag() {};
};

enum OpponentType { MadBear = 0, Bandit, LordLupin, Elf, Troll, Tornbery, QueenOfCards, NinaDeRings, DurianGarden, OmegaWeapon, Hades };

class BaseOpponent{
protected:
    int id;
    int dmg;
    int gil;
    OpponentType opponentType;
public:
    static BaseOpponent * create(int id, int dmg, int gil, OpponentType opponentType);
    virtual ~BaseOpponent() {};
};

enum KnightType { PALADIN = 0, LANCELOT, DRAGON, NORMAL };

class BaseKnight {
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    int antidote;
    int phoenixdownI;
    BaseBag * bag;
    KnightType knightType;
public:
    static BaseKnight * create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;
    virtual void fight(BaseOpponent * opponent) = 0;
    virtual ~BaseKnight() {};
};

class Paladin : public BaseKnight {
public:
    Paladin(int id, int hp, int level, int gil, int antidote, int phoenixdownI)
    {
        this->id = id;
        this->hp = isPrime(hp);
        this->maxhp = this->hp;
        this->level = level;
        this->gil = gil;
        this->antidote = antidote;
        this->phoenixdownI = phoenixdownI;
        this->knightType = PALADIN;
    }

    static bool isPrime(int n)
    {
        if (n <= 1) return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    void fight(BaseOpponent* opponent) override {
        // implement fight method for PaladinKnight
    }
};

class Lancelot : public BaseKnight {
public:
    Lancelot(int id, int level, int gil, int antidote, int phoenixdownI)
    {
        this->id = id;
        this->hp = 888;
        this->maxhp = this->hp;
        this->level = level;
        this->gil = gil;
        this->antidote = antidote;
        this->phoenixdownI = phoenixdownI;
        this->knightType = LANCELOT;
    }

    void fight(BaseOpponent* opponent) override {
        // implement fight method for LancelotKnight
    }
};

class DragonKnight : public BaseKnight {
public:
    DragonKnight(int id, int level, int gil, int antidote, int phoenixdownI)
    {
        this->id = id;
        this->hp = getPythagoreanTriple();
        this->maxhp = this->hp;
        this->level = level;
        this->gil = gil;
        this->antidote = antidote;
        this->phoenixdownI = phoenixdownI;
        this->knightType = DRAGON;
    }

    static bool isPythagoreanTriple(int a, int b, int c)
    {
        return (a * a + b * b == c * c);
    }

    static int getPythagoreanTriple()
    {
        int a, b, c;
        do {
            a = rand() % 100 + 1;
            b = rand() % 100 + 1;
            c = rand() % 100 + 1;
        } while (!isPythagoreanTriple(a, b, c) || to_string(c).size() != 3);
        return c;
    }

    void fight(BaseOpponent* opponent) override {
        // implement fight method for DragonKnight
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
    ~KnightAdventure(); // TODO:

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