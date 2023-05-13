#include "knight2.h"

/* * BEGIN implementation of submodules * * */
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isPythagoreanTriple(int n)
{
    int a, b, c;
    stringstream ss = stringstream(to_string(n));
    ss >> a >> b >> c;
    return (a * a + b * b == c * c);
}

int HPtype(int hp)
{
    // check if HP is an int between 1 & 999
    if (hp < 1 || hp > 999) return -1;
    // check if HP is a prime number
    else if (isPrime(hp)) return 0;
    // check if HP == 888
    else if (hp == 888) return 1;
    // check if HP has exactly 3 digits and form Pythogorean triple
    else if (hp <= 999) {
        if (hp >= 100 && isPythagoreanTriple(hp)) return 2;
        else return 3;
    }
    return 4;
}
/* * * END implementation of submodules * * */

/* * * BEGIN implementation of class BaseBag * * */
bool BaseBag::insertFirst(BaseItem *item)
{
    if (size >= maxSize) return false;
    Node *newNode = new Node(item);
    newNode->next = head;
    head = newNode;
    size++;
    return true;
}

void BaseBag::remove(BaseItem *item)
{
    Node *current = head;
    Node *prev = nullptr;

    while (current != nullptr)
    {
        if (current->item == item) {
            if (prev != nullptr) prev->next = current->next;
            else head = current->next;  // Update the head if removing the first node

            delete current->item;
            delete current;
            size--;
            return;  // Exit the function after removing the first occurrence
        }
        prev = current;
        current = current->next;
    }
}

void BaseBag::empty()
{
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->next;
        delete current->item;
        current = next;
    }
    head = nullptr;
    size = 0;
}

bool BaseBag::removeFirst()
{
    if (size == 0) return false;
    Node *temp = head;
    head = head->next;
    delete temp;
    size--;
    return true;
}

BaseItem *BaseBag::get(ItemType itemType)
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->item->itemType == itemType)
        {
            return current->item;
        }
        current = current->next;
    }
    return nullptr;
}

string BaseBag::toString() const
{
    string typeString[5] = {"Antidote", "PhoenixI", "PhoenixII", "PhoenixIII", "PhoenixIV"};
    Node *current = head;
    string items;
    while (current != nullptr)
    {
        items += typeString[current->item->itemType];
        items += ",";
        current = current->next;
        if (current == nullptr)
            items = items.substr(0, items.size() - 1);
    }
    return "Bag[count=" + to_string(size) + ";" + items + "]";
}

BaseBag::~BaseBag()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *next = current->next;
        delete current->item;
        current = next;
    }
}
/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseOpponent * * */
class MadBear : public BaseOpponent
{
public:
    MadBear(int level, int dmg, int gil, OpponentType opponentType)
    {
        this->level = level;
        this->dmg = 10;
        this->gil = gil;
        this->opponentType = opponentType;
    }
    ~MadBear() {}
};

class Bandit : public BaseOpponent
{
public:
    Bandit(int level, int dmg, int gil, OpponentType opponentType)
    {
        this->level = level;
        this->dmg = 15;
        this->gil = gil;
        this->opponentType = opponentType;
    }
    ~Bandit() {}
};

class LordLupin : public BaseOpponent
{
public:
    LordLupin(int level, int dmg, int gil, OpponentType opponentType)
    {
        this->level = level;
        this->dmg = 45;
        this->gil = gil;
        this->opponentType = opponentType;
    }
    ~LordLupin() {}
};

class Elf : public BaseOpponent
{
public:
    Elf(int level, int dmg, int gil, OpponentType opponentType)
    {
        this->level = level;
        this->dmg = 75;
        this->gil = gil;
        this->opponentType = opponentType;
    }
    ~Elf() {}
};

class Troll : public BaseOpponent
{
public:
    Troll(int level, int dmg, int gil, OpponentType opponentType)
    {
        this->level = level;
        this->dmg = 95;
        this->gil = gil;
        this->opponentType = opponentType;
    }
    ~Troll() {}
};

class Tornbery : public BaseOpponent
{
public:
    Tornbery(int level, int dmg, int gil, OpponentType opponentType)
    {
        this->level = level;
        this->dmg = dmg;
        this->gil = gil;
        this->opponentType = opponentType;
    }
    ~Tornbery() {}
};

class QueenOfCards : public BaseOpponent
{
public:
    QueenOfCards(int level, int dmg, int gil, OpponentType opponentType)
    {
        this->level = level;
        this->dmg = dmg;
        this->gil = gil;
        this->opponentType = opponentType;
    }
    ~QueenOfCards() {}
};

class NinaDeRings : public BaseOpponent
{
public:
    NinaDeRings(int level, int dmg, int gil, OpponentType opponentType)
    {
        this->level = level;
        this->dmg = dmg;
        this->gil = gil;
        this->opponentType = opponentType;
    }
    ~NinaDeRings() {}
};

class DurianGarden : public BaseOpponent
{
public:
    DurianGarden(int level, int dmg, int gil, OpponentType opponentType)
    {
        this->level = level;
        this->dmg = dmg;
        this->gil = gil;
        this->opponentType = opponentType;
    }
    ~DurianGarden() {}
};

class OmegaWeapon : public BaseOpponent
{
public:
    OmegaWeapon(int level, int dmg, int gil, OpponentType opponentType)
    {
        this->level = level;
        this->dmg = dmg;
        this->gil = gil;
        this->opponentType = opponentType;
    }
    ~OmegaWeapon() {}
};

class Hades : public BaseOpponent
{
public:
    Hades(int level, int dmg, int gil, OpponentType opponentType)
    {
        this->level = level;
        this->dmg = dmg;
        this->gil = gil;
        this->opponentType = opponentType;
    }
    ~Hades() {}
};

class Ultimecia : public BaseOpponent
{
public:
    Ultimecia(int level, int dmg, int gil, OpponentType opponentType)
    {
        this->level = level;
        this->dmg = dmg;
        this->gil = gil;
        this->hp = 5000;
        this->opponentType = opponentType;
    }
    ~Ultimecia() {}
};

BaseOpponent *BaseOpponent::create(int level, int dmg, int gil, OpponentType opponentType)
{
    switch (opponentType)
    {
    case MBear:
        return new MadBear(level, dmg, gil, opponentType);
        break;
    case Bdit:
        return new Bandit(level, dmg, gil, opponentType);
        break;
    case Lupin:
        return new LordLupin(level, dmg, gil, opponentType);
        break;
    case ELF:
        return new Elf(level, dmg, gil, opponentType);
        break;
    case TROLL:
        return new Troll(level, dmg, gil, opponentType);
        break;
    case Tbery:
        return new Tornbery(level, dmg, gil, opponentType);
        break;
    case QCard:
        return new QueenOfCards(level, dmg, gil, opponentType);
        break;
    case NRing:
        return new NinaDeRings(level, dmg, gil, opponentType);
        break;
    case DGarden:
        return new DurianGarden(level, dmg, gil, opponentType);
        break;
    case OWeapon:
        return new OmegaWeapon(level, dmg, gil, opponentType);
        break;
    case HADES:
        return new Hades(level, dmg, gil, opponentType);
        break;
    case ULTI:
        return new Ultimecia(level, dmg, gil, opponentType);
        break;
    default:
        break;
    }
    return nullptr;
}
/* * * END implementation of class BaseOpponent * * */

/* * * BEGIN implementation of class BaseItem * * */
class Antidote : public BaseItem
{
public:
    Antidote() {
        this->itemType = ANTIDOTE;
    }
    virtual bool canUse(BaseKnight *knight) {
        return knight->isPoisoned;
    }
    virtual void use(BaseKnight *knight) {
        knight->isPoisoned = false;
        knight->getBag()->remove(this);
    }
    ~Antidote() {}
};

class PhoenixDownI : public BaseItem
{
public:
    PhoenixDownI()
    {
        this->itemType = PHOENIXDOWN_I;
    }
    virtual bool canUse(BaseKnight *knight)
    {
        return knight->getCurrentHP() <= 0;
    }

    virtual void use(BaseKnight *knight)
    {
        knight->restoreHP();
        knight->getBag()->remove(this);
    }
    ~PhoenixDownI() {}
};

class PhoenixDownII : public BaseItem
{
public:
    PhoenixDownII()
    {
        this->itemType = PHOENIXDOWN_II;
    }
    virtual bool canUse(BaseKnight *knight)
    {
        return knight->getCurrentHP() < knight->getMaxHP() / 4;
    }

    virtual void use(BaseKnight *knight)
    {
        knight->restoreHP();
        knight->getBag()->remove(this);
    }
    ~PhoenixDownII() {}
};

class PhoenixDownIII : public BaseItem
{
public:
    PhoenixDownIII()
    {
        this->itemType = PHOENIXDOWN_III;
    }
    virtual bool canUse(BaseKnight *knight)
    {
        int max_hp = knight->getMaxHP();
        int current_hp = knight->getCurrentHP();

        if (current_hp <= 0) return true;
        else if (current_hp < max_hp / 4) return true;
        else return false;
    }

    virtual void use(BaseKnight *knight)
    {
        int max_hp = knight->getMaxHP();
        int current_hp = knight->getCurrentHP();

        if (current_hp <= 0)
        {
            knight->restoreHP(max_hp / 3);
        }
        else
        {
            knight->restoreHP(max_hp / 4);
        }
        knight->getBag()->remove(this);
    }

    ~PhoenixDownIII() {}
};

class PhoenixDownIV : public BaseItem
{
public:
    PhoenixDownIV()
    {
        this->itemType = PHOENIXDOWN_IV;
    }
    virtual bool canUse(BaseKnight *knight)
    {
        int max_hp = knight->getMaxHP();
        int current_hp = knight->getCurrentHP();

        if (current_hp <= 0)
        {
            return true;
        }
        else if (current_hp < max_hp / 5)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    virtual void use(BaseKnight *knight)
    {
        int max_hp = knight->getMaxHP();
        int current_hp = knight->getCurrentHP();

        if (current_hp <= 0)
        {
            knight->restoreHP(max_hp / 2);
        }
        else
        {
            knight->restoreHP(max_hp / 5);
        }
        knight->getBag()->remove(this);
    }

    ~PhoenixDownIV() {}
};
/* * * END implementation of class BaseItem * * */

/* * * BEGIN implementation of class Knight's Bag * * */
class PaladinBag : public BaseBag
{
public:
    PaladinBag(BaseKnight *knight, int a, int b) : BaseBag(knight, -1)
    {
        // Initialize bag with any provided items
        for (int i = 0; i < a; i++)
        {
            // insertFirst(new PhoenixDownI());
            PaladinBag::insertFirst(new PhoenixDownII());
        }
        for (int i = 0; i < b; i++)
        {
            // insertFirst(new Antidote());
            PaladinBag::insertFirst(new PhoenixDownIII());
        }
    }
    string toString() const override
    {
        return BaseBag::toString();
    }
    ~PaladinBag() {}
};

class LancelotBag : public BaseBag
{
public:
    LancelotBag(BaseKnight *knight, int a, int b) : BaseBag(knight, 16)
    {
        // Initialize bag with any provided items
        for (int i = 0; i < a; i++)
        {
            insertFirst(new PhoenixDownI());
        }
        for (int i = 0; i < b; i++)
        {
            insertFirst(new Antidote());
        }
    }
    string toString() const override
    {
        return BaseBag::toString();
    }
    ~LancelotBag() {}
};

class NormalBag : public BaseBag
{
public:
    NormalBag(BaseKnight *knight, int a, int b) : BaseBag(knight, 19)
    {
        // Initialize bag with any provided items
        for (int i = 0; i < a; i++)
        {
            insertFirst(new PhoenixDownI());
        }
        for (int i = 0; i < b; i++)
        {
            insertFirst(new Antidote());
        }
    }
    string toString() const
    {
        return BaseBag::toString();
    }
    ~NormalBag() {}
};

class DragonBag : public BaseBag
{
public:
    DragonBag(BaseKnight *knight, int a, int b) : BaseBag(knight, 14)
    {
        // Initialize bag with any provided items
        for (int i = 0; i < a; i++)
        {
            insertFirst(new PhoenixDownI());
        }
        // Dragon Knight does not have antidote in their bag
        if (b > 0)
        {
            // If the Dragon Knight picks up an antidote, pass it to the Knight in front
            if (knight->getFront() != nullptr)
            {
                knight->getFront()->getBag()->insertFirst(new Antidote());
            }
        }
    }
    string toString() const override
    {
        return BaseBag::toString();
    }
    ~DragonBag() {}
};
/* * * END implementation of class Knight's Bag * * */

/* * * BEGIN implementation of class BaseKnight * * */
string BaseKnight::toString() const
{
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    stringstream ss;
    ss << "[Knight:id:" << this->id
       << ",hp:" << this->hp
       << ",maxhp:" << this->maxhp
       << ",level:" << this->level
       << ",gil:" << this->gil
       << "," << this->bag->toString()
       << ",knight_type:" << typeString[this->knightType]
       << "]";
    return ss.str();
}

void BaseKnight::handleHP() {
    if (hp <= 0 
        && bag->get(PHOENIXDOWN_I) 
        && bag->get(PHOENIXDOWN_I)->canUse(this)) {
            bag->get(PHOENIXDOWN_I)->use(this);
        }
    else if (hp <= 0 && !bag->get(PHOENIXDOWN_I)) {
        if (this->gil > 100) {
            this->gil = this->gil - 100;
            this->hp = this->maxhp / 2;
        } else {
            deleteKnight(this);
        }
    }
}

class Paladin : public BaseKnight
{
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
        this->bag = new PaladinBag(this, phoenixdownI, antidote);
        this->knightType = PALADIN;
    }
    void fight(BaseOpponent *opponent) override
    {
        // implement fight method for PaladinKnight
        switch (opponent->opponentType)
        {
            case MBear:
            case Lupin:
            case Bdit:
            case ELF:
            case TROLL:
                gil = min(gil + opponent->gil, 999);
                break;
            default:
                return BaseKnight::fight(opponent);
                break;
        }
    }
};

class Lancelot : public BaseKnight
{
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
        this->bag = new LancelotBag(this, phoenixdownI, antidote);
        this->knightType = LANCELOT;
    }

    void fight(BaseOpponent *opponent) override
    {
        return BaseKnight::fight(opponent);
    }
};

class DragonKnight : public BaseKnight
{
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
        this->bag = new DragonBag(this, phoenixdownI, antidote);
        this->knightType = DRAGON;
    }

    void fight(BaseOpponent *opponent) override
    {
        return BaseKnight::fight(opponent);
    }
};

class NormalKnight : public BaseKnight
{
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
        this->bag = new NormalBag(this, phoenixdownI, antidote);
        this->knightType = NORMAL;
    }

    void fight(BaseOpponent *opponent) override
    {
        // implement fight method for NormalKnight
        return BaseKnight::fight(opponent);
    }
};

BaseKnight *BaseKnight::deleteKnight(BaseKnight *knight) {
    BaseKnight* prevKnight = nullptr;
    BaseKnight* currKnight = this;

    while (currKnight->nextKnight != nullptr) {
        prevKnight = currKnight;
        currKnight = currKnight->nextKnight;
    }

    if (prevKnight != nullptr) {
        prevKnight->nextKnight = nullptr;  // Remove the reference to the current knight
        delete currKnight;  // Delete the current knight
        return prevKnight;
    } else {
        // Special case when the current knight is the first knight
        BaseKnight* nextKnight = currKnight->nextKnight;
        delete currKnight;
        return nextKnight;
    }
}

BaseKnight *BaseKnight::create(int id, int hp, int level, int gil, int antidote, int phoenixdownI)
{
    int type = HPtype(hp);
    switch (type)
    {
    case -1:
        cout << "Invalid HP type" << endl;
        exit(EXIT_FAILURE);
    case 0:
        return new Paladin(id, hp, level, gil, antidote, phoenixdownI);
        break;
    case 1:
        return new Lancelot(id, hp, level, gil, antidote, phoenixdownI);
        break;
    case 2:
        return new DragonKnight(id, hp, level, gil, antidote, phoenixdownI);
        break;
    case 3:
        return new NormalKnight(id, hp, level, gil, antidote, phoenixdownI);
        break;
    case 4:
        cout << "Invalid logic" << endl;
        break;
    default:
        break;
    }
    return nullptr;
}

void BaseKnight::fight(BaseOpponent *opponent)
{
    int levelO = opponent->level;
    if (level >= levelO)
    {
        switch (opponent->opponentType)
        {
            case MBear:
            case Lupin:
            case Bdit:
            case ELF:
            case TROLL:
                gil = min(gil + opponent->gil, 999);
                break;
            case Tbery:
            {
                if (level < 10) level += 1;
                break;
            }
            case QCard:
            {
                int temp = gil * 2 - 999;
                gil = min(gil * 2, 999);
                BaseKnight *curr = this;
                BaseKnight *nextKnight = curr->nextKnight;

                while (temp > 0 && nextKnight != nullptr)
                {
                    nextKnight->gil = min(nextKnight->gil + temp, 999);
                    temp = temp - nextKnight->gil;
                    curr = nextKnight;
                    nextKnight = curr->nextKnight;
                }

                // Perform the deletion after the loop
                if (curr->nextKnight != nullptr)
                {
                    BaseKnight *knightToDelete = curr->nextKnight;
                    curr->nextKnight = knightToDelete->nextKnight;
                    delete knightToDelete;
                }

                break;
            }

            case NRing:
            {
                if (gil >= 50 && hp < (maxhp / 3)) {
                    gil = gil - 50;
                    hp += maxhp / 5;
                }
                break;
            }
            case DGarden:
            {
                hp = maxhp;
                break;
            }
            case HADES:
            {

                break;
            }

            default:
            {
                cout << "Invalid opponent type: " << opponent->opponentType << endl;
                break;
            }
        }
    }
    else
    {
        switch (opponent->opponentType)
        {
            case MBear:
            case Lupin:
            case Bdit:
            case ELF:
            case TROLL:
            {
                hp = hp - opponent->dmg * (levelO - level);
                handleHP();
                break;
            }
            case Tbery:
            {
                isPoisoned = true;
                if (bag->get(ANTIDOTE) && bag->get(ANTIDOTE)->canUse(this)) {
                    bag->get(ANTIDOTE)->use(this);
                }
                else
                {
                    hp -= 10;
                    handleHP();
                    if (bag->getSize() > 3)
                    {
                        bag->removeFirst();
                        bag->removeFirst();
                        bag->removeFirst();
                        break;
                    }
                    else if (bag->getSize() <= 3)
                    {
                        bag->empty();
                        break;
                    }

                }
                break;
            }
            case QCard:
            {
                gil = gil / 2;
                break;
            }
            case NRing:
            {
                if (gil >= 50 && hp < (maxhp / 3)) {
                    gil = gil - 50;
                    hp += maxhp / 5;
                }
                break;
            }
            case OWeapon:
            {
                if ((level == 10 && hp == maxhp) || knightType == DRAGON) {
                    level = 10;
                    gil = 999;
                }
                else {
                    hp = 0;
                    handleHP();
                }
                break;
            }
            case HADES:
            {
                handleHP();
                break;
            }

            default:
            {
                cout << "Invalid opponent type: " << opponent->opponentType << endl;
                // else if (bag->get(PHOENIXDOWN_II)
                // && bag->get(PHOENIXDOWN_II)->canUse(this)) {
                //     bag->get(PHOENIXDOWN_II)->use(this);
                // }
                // else if (bag->get(PHOENIXDOWN_III)
                // && bag->get(PHOENIXDOWN_III)->canUse(this)) {
                //     bag->get(PHOENIXDOWN_III)->use(this);
                // }
                // else if (bag->get(PHOENIXDOWN_IV)
                // && bag->get(PHOENIXDOWN_IV)->canUse(this)) {
                //     bag->get(PHOENIXDOWN_IV)->use(this);
                // }
                break;
            }
        }
    }
}
/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */
void ArmyKnights::printInfo() const
{
    cout << "No. knights: " << this->count();
    if (this->count() > 0)
    {
        BaseKnight *lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
         << ";LancelotSpear:" << this->hasLancelotSpear()
         << ";GuinevereHair:" << this->hasGuinevereHair()
         << ";ExcaliburSword:" << this->hasExcaliburSword()
         << endl
         << string(50, '-') << endl;
}

ArmyKnights::ArmyKnights(const string &file_armyknights)
{
    ifstream fin(file_armyknights);
    if (!fin)
    {
        cerr << "Unable to open input file" << endl;
        exit(EXIT_FAILURE);
    }

    int n;
    if (!(fin >> n))
    {
        cerr << "Error reading first line from input file" << endl;
        exit(EXIT_FAILURE);
    }

    if (n <= 0 || n > 1000)
    {
        cerr << "Invalid number of knights" << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
    {
        int hp, level, pd, gil, antidote;
        if (!(fin >> hp >> level >> pd >> gil >> antidote))
        {
            cerr << "Error reading knight information from input file" << endl;
            exit(EXIT_FAILURE);
        }
        knights[i] = BaseKnight::create(i + 1, hp, level, gil, antidote, pd);
        count_++;

        if (i < n - 1)
        {
            knights[i]->setNextKnight(knights[i + 1]);
        }
    }
}

ArmyKnights::~ArmyKnights()
{
    for (int i = 0; i < count_; i++)
    {
        delete knights[i];
    }
}

bool ArmyKnights::fight(BaseOpponent *opponent)
{
    // knights[0]->fight(opponent);
    lastKnight()->fight(opponent);
    return false;
}

bool ArmyKnights::adventure(Events *events)
{
    int n = events->count();
    static int hadOW = 0;
    static int hadHD = 0;
    for (int i = 0; i < n; i++)
    {
        int code = events->get(i);
        int levelO = (i + code) % 10 + 1;
        switch (code)
        {
        case 1:
        {
            BaseOpponent *MadBear = BaseOpponent::create(levelO, 10, 100, MBear);
            lastKnight()->fight(MadBear);
            delete MadBear;
            break;
        }
        case 2:
        {
            BaseOpponent *Bandit = BaseOpponent::create(levelO, 15, 150, Bdit);
            lastKnight()->fight(Bandit);
            delete Bandit;
            break;
        }
        case 3:
        {
            BaseOpponent *LordLupin = BaseOpponent::create(levelO, 45, 450, Lupin);
            lastKnight()->fight(LordLupin);
            delete LordLupin;
            break;
        }
        case 4:
        {
            BaseOpponent *Elf = BaseOpponent::create(levelO, 75, 750, ELF);
            lastKnight()->fight(Elf);
            delete Elf;
            break;
        }
        case 5:
        {
            BaseOpponent *Troll = BaseOpponent::create(levelO, 95, 800, TROLL);
            lastKnight()->fight(Troll);
            delete Troll;
            break;
        }
        case 6:
        {
            BaseOpponent *Tornbery = BaseOpponent::create(levelO, 10, 100, Tbery);
            lastKnight()->fight(Tornbery);
            delete Tornbery;
            break;
        }
        case 7:
        {
            BaseOpponent *QoC = BaseOpponent::create(levelO, 10, 100, QCard);
            lastKnight()->fight(QoC);
            delete QoC;
            break;
        }
        case 8:
        {
            BaseOpponent *Niring = BaseOpponent::create(levelO, 10, 100, NRing);
            lastKnight()->fight(Niring);
            delete Niring;
            break;
        }
        case 9:
        {
            BaseOpponent *DuGarden = BaseOpponent::create(levelO, 10, 100, DGarden);
            lastKnight()->fight(DuGarden);
            delete DuGarden;
            break;
        }
        case 10:
        {
            BaseOpponent *OmWeapon = BaseOpponent::create(999, 10, 100, OWeapon);
            lastKnight()->fight(OmWeapon);
            delete OmWeapon;
            break;
        }
        case 11:
        {
            BaseOpponent *Hdes = BaseOpponent::create(999, 10, 100, HADES);
            if (hadHD == 0) {
                if ((lastKnight()->getKnightType() == PALADIN 
                && lastKnight()->getLevel() >= 8)
                || lastKnight()->getLevel() == 10) {
                    PaladinShield = 1;
                    hadHD = 1;
                    break;
                }
                else {
                    lastKnight()->fight(Hdes);
                }
            }
            delete Hdes;
            break;
        }
        case 112:
        {
            lastKnight()->getBag()->insertFirst(new PhoenixDownII);
            break;
        }
        case 113:
        {
            lastKnight()->getBag()->insertFirst(new PhoenixDownIII);
            break;
        }
        case 114:
        {
            lastKnight()->getBag()->insertFirst(new PhoenixDownIV);
            break;
        }
        case 95:
        {
            PaladinShield = 1;
            break;
        }
        case 96:
        {
            LancelotSpear = 1;
            break;
        }
        case 97:
        {
            GuinevereHair = 1;
            break;
        }
        case 98:
        {
            if (ArmyKnights::hasPaladinShield() 
            && ArmyKnights::hasLancelotSpear() 
            && ArmyKnights::hasGuinevereHair()) ExcaliburSword = 1;
            break;
        }
        case 99:
        {
            BaseOpponent *Ultimecia = BaseOpponent::create(999, 0, 0, ULTI);
            if (ArmyKnights::hasExcaliburSword())
            {
                // for (int j = 0; j < count_; j++) {
                //     delete knights[j];
                //     knights[j] = nullptr;  // Set the deleted pointer to null
                //     count_ --;
                // }
                break;
            }
            else if (ArmyKnights::hasPaladinShield() && ArmyKnights::hasLancelotSpear() && ArmyKnights::hasGuinevereHair())
            {
                if (lastType() == nullptr)
                {
                    for (int j = 0; j < count_; j++)
                    {
                        // delete knights[j];
                        // knights[j] = nullptr;  // Set the deleted pointer to null
                        count_--;
                    }
                    break;
                }
                else
                {
                    lastType()->fight(Ultimecia);
                }
                delete Ultimecia;
                break;
            }
            delete Ultimecia;
            break;
        }
        default:
            break;
        }

        if (lastKnight() == nullptr)
        {
            printInfo();
            break;
        }
        // else if (lastKnight()->getCurrentHP() <= 0 && lastKnight()->getBag()->get(PHOENIXDOWN_I))
        // {
        //     lastKnight()->restoreHP();
        //     lastKnight()->getBag()->removeFirst();
        //     printInfo();
        // }
        // else if (lastKnight()->getCurrentHP() < lastKnight()->getMaxHP() && lastKnight()->getBag()->get(ANTIDOTE))
        // {
        //     lastKnight()->restoreHP();
        //     lastKnight()->getBag()->removeFirst();
        //     printInfo();
        // }
        else
        {
            printInfo();
        }
    }
    return false;
}

int ArmyKnights::count() const
{
    return count_;
}

BaseKnight *ArmyKnights::lastKnight() const
{
    if (count_ == 0)
    {
        return nullptr;
    }
    int index = count_ - 1;
    while (!knights[index])
    {
        index--;
        if (index < 0)
        {
            // If all Knights have fallen, return nullptr.
            return nullptr;
        }
    }
    return knights[index];
}

BaseKnight *ArmyKnights::lastType() const
{
    if (count_ == 0)
    {
        return nullptr;
    }
    int index = count_ - 1;
    while (!knights[index])
    {
        index--;
        if (index < 0)
        {
            // If all Knights have fallen, return nullptr.
            return nullptr;
        }
    }
    if (knights[index]->getKnightType() == PALADIN ||
        knights[index]->getKnightType() == LANCELOT ||
        knights[index]->getKnightType() == DRAGON)
    {
        return knights[index];
    }
    return nullptr;
}

bool ArmyKnights::hasPaladinShield() const
{
    if (PaladinShield > 0)
    {
        return true;
    }
    return false;
}

bool ArmyKnights::hasLancelotSpear() const
{
    if (LancelotSpear > 0)
    {
        return true;
    }
    return false;
}

bool ArmyKnights::hasGuinevereHair() const
{
    if (GuinevereHair > 0)
    {
        return true;
    }
    return false;
}

bool ArmyKnights::hasExcaliburSword() const
{
    if (ExcaliburSword > 0)
    {
        return true;
    }
    return false;
}

void ArmyKnights::printResult(bool win) const
{
    cout << (win ? "WIN" : "LOSE") << endl;
}
/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure()
{
    armyKnights = nullptr;
    events = nullptr;
}

KnightAdventure::~KnightAdventure()
{
    delete armyKnights;
}

void KnightAdventure::run()
{
    armyKnights->adventure(events);
    BaseKnight *lknight = armyKnights->lastKnight();
    if (lknight == nullptr)
    {
        armyKnights->printResult(false);
    }
    else if (armyKnights->hasExcaliburSword())
        armyKnights->printResult(true);
    else
    {
        armyKnights->printResult(true);
    }
}
/* * * END implementation of class KnightAdventure * * */

/* * * BEGIN implementation of class Events * * */
Events::Events(const string &file_events)
{
    ifstream fin(file_events);
    if (!fin)
    {
        cerr << "Unable to open input file" << endl;
        exit(EXIT_FAILURE);
    }
    fin >> num_events;

    event_codes = new int[num_events];

    for (int i = 0; i < num_events; i++)
    {
        fin >> event_codes[i];
    }
    fin.close();
}

Events::~Events()
{
    delete[] event_codes;
}

int Events::count() const
{
    return num_events;
}

int Events::get(int i) const
{
    return event_codes[i];
}
/* * END implementation of class Events * * */

bool BaseItem::canUse(BaseKnight *knight)
{
    return false;
}

void BaseItem::use(BaseKnight *knight)
{
}