#include "knight2.h"

/* * BEGIN implementation of submodules * * */
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isPythagoreanTriple(int n) {
    int a, b, c;
    stringstream ss = stringstream(to_string(n));
    ss >> a >> b >> c;
    return (a * a + b * b == c * c);
}

int HPtype(int hp) {
    //check if HP is an int between 1 & 999
    if (hp < 1 || hp > 999) {
        return -1;
    }
    //check if HP is a prime number
    else if (isPrime(hp)) {
        return 0;
    }
    //check if HP == 888
    else if (hp == 888) {
        return 1;
    }
    //check if HP has exactly 3 digits and form Pythogorean triple
    else if (hp >= 100 && hp <= 999) {
        return isPythagoreanTriple(hp) ? 2 : 3;
    }
    return 4;
}
/* * * END implementation of submodules * * */

/* * * BEGIN implementation of class BaseBag * * */
bool BaseBag::insertFirst(BaseItem * item) {
    if (size >= maxSize) {
        return false; // Bag is full
    }
    Node* newNode = new Node(item);
    newNode->next = head;
    head = newNode;
    size++;
    return true;
}

BaseItem *BaseBag::get(ItemType itemType) {
    // Return the first item in the list
    Node* current = head;
    while (current != nullptr) {
        if (current->item->itemType == itemType) {
            return current->item;
        }
        current = current->next;
    }
    return nullptr;
}

string BaseBag::toString() const {
    cout << "test" << endl;
    int count = 0;
    Node* current = head;
    string items;
    while (current != nullptr) {
        if (current->item->itemType == ANTIDOTE) {
            current = current->next;
            continue;
        }
        count++;
        items += current->item->itemType;
        if (current->next != nullptr && current->item->itemType != ANTIDOTE) {
            items += ",";
        }
        current = current->next;
    }
    return "Bag[count=" + to_string(count) + ";" + items + "]";
}

BaseBag::~BaseBag() {
    // Delete all nodes in the list
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current->item;
        current = next;
    }
}
/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseOpponent * * */
class MadBear : public BaseOpponent {
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

class Bandit : public BaseOpponent {
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

class LordLupin : public BaseOpponent {
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

class Elf : public BaseOpponent {
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

class Troll : public BaseOpponent {
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

class Tornbery : public BaseOpponent {
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

class QueenOfCards : public BaseOpponent {
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

class NinaDeRings : public BaseOpponent {
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

class DurianGarden : public BaseOpponent {
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

class OmegaWeapon : public BaseOpponent {
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

class Hades : public BaseOpponent {
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

BaseOpponent *BaseOpponent::create(int level, int dmg, int gil, OpponentType opponentType){
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
        case QCards:
            return new QueenOfCards(level, dmg, gil, opponentType);
            break;
        case NRings:
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
        default:
            break;
    }
    return nullptr;
}
/* * * END implementation of class BaseOpponent * * */

/* * * BEGIN implementation of class BaseItem * * */
class Antidote : public BaseItem {
public:
    virtual bool canUse(BaseKnight* knight) {
        return knight->isPoisoned;
    }

    virtual void use(BaseKnight* knight) {
        knight->curePoison();
    }
    ~Antidote() {}
};

class PhoenixDownI : public BaseItem {
public:
    virtual bool canUse(BaseKnight* knight) {
        return knight->getCurrentHP() <= 0;
    }

    virtual void use(BaseKnight* knight) {
        knight->restoreHP(knight->getMaxHP());
    }
    ~PhoenixDownI () {}
};

class PhoenixDownII : public BaseItem {
public:
    virtual bool canUse(BaseKnight* knight) {
        return knight->getCurrentHP() < knight->getMaxHP() / 4;
    }

    virtual void use(BaseKnight* knight) {
        knight->restoreHP(knight->getMaxHP());
    }
    ~PhoenixDownII () {}
};

class PhoenixDownIII : public BaseItem {
public:
    virtual bool canUse(BaseKnight* knight) {
        int max_hp = knight->getMaxHP();
        int current_hp = knight->getCurrentHP();

        if (current_hp <= 0) {
            return true;
        }
        else if (current_hp < max_hp / 4) {
            return true;
        }
        else {
            return false;
        }
    }

    virtual void use(BaseKnight* knight) {
        int max_hp = knight->getMaxHP();
        int current_hp = knight->getCurrentHP();

        if (current_hp <= 0) {
            knight->restoreHP(max_hp / 3);
        }
        else {
            knight->restoreHP(max_hp / 4);
        }
    }

    ~PhoenixDownIII () {}
};

class PhoenixDownIV : public BaseItem {
public:
    virtual bool canUse(BaseKnight* knight) {
        int max_hp = knight->getMaxHP();
        int current_hp = knight->getCurrentHP();

        if (current_hp <= 0) {
            return true;
        }
        else if (current_hp < max_hp / 5) {
            return true;
        }
        else {
            return false;
        }
    }

    virtual void use(BaseKnight* knight) {
        int max_hp = knight->getMaxHP();
        int current_hp = knight->getCurrentHP();

        if (current_hp <= 0) {
            knight->restoreHP(max_hp / 2);
        }
        else {
            knight->restoreHP(max_hp / 5);
        }
    }

    ~PhoenixDownIV () {}
};
/* * * END implementation of class BaseItem * * */

/* * * BEGIN implementation of class Knight's Bag * * */
class PaladinBag : public BaseBag {
public:
    PaladinBag(BaseKnight* knight, int a, int b) : BaseBag(knight, -1) {
        // Initialize bag with any provided items
        for (int i = 0; i < a; i++) {
            insertFirst(new PhoenixDownI());
        }
        for (int i = 0; i < b; i++) {
            insertFirst(new Antidote());
        }
    }
    string toString() const override {
        return BaseBag::toString();
    }
    ~PaladinBag() {}
};

class LancelotBag : public BaseBag {
public:
    LancelotBag(BaseKnight* knight, int a, int b) : BaseBag(knight, 16) {
        // Initialize bag with any provided items
        for (int i = 0; i < a; i++) {
            insertFirst(new PhoenixDownI());
        }
        for (int i = 0; i < b; i++) {
            insertFirst(new Antidote());
        }
    }
    string toString() const override {
        return BaseBag::toString();
    }
    ~LancelotBag() {}
};

class NormalBag : public BaseBag {
public:
    NormalBag(BaseKnight* knight, int a, int b) : BaseBag(knight, 19) {
        // Initialize bag with any provided items
        for (int i = 0; i < a; i++) {
            insertFirst(new PhoenixDownI());
        }
        for (int i = 0; i < b; i++) {
            insertFirst(new Antidote());
        }
    }
    string toString() const override {
        return BaseBag::toString();
    }
    ~NormalBag() {}
};

class DragonBag : public BaseBag {
public:
    DragonBag(BaseKnight* knight, int a, int b) : BaseBag(knight, 14) {
        // Initialize bag with any provided items
        for (int i = 0; i < a; i++) {
            insertFirst(new PhoenixDownI());
        }
        // Dragon Knight does not have antidote in their bag
        if (b > 0) {
            // If the Dragon Knight picks up an antidote, pass it to the Knight in front
            if (knight->getFront() != nullptr) {
                knight->getFront()->getBag()->insertFirst(new Antidote());
            }
        }
    }
    string toString() const override {
        return BaseBag::toString();
    }
    ~DragonBag() {}
};
/* * * END implementation of class Knight's Bag * * */

/* * * BEGIN implementation of class BaseKnight * * */
string BaseKnight::toString() const {
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
// string BaseKnight::toString() const {
//     string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
//     // inefficient version, students can change these code
//     //      but the format output must be the same
//     string s("");
//     s += "[Knight:id:" + to_string(id) 
//         + ",hp:" + to_string(hp) 
//         + ",maxhp:" + to_string(maxhp)
//         + ",level:" + to_string(level)
//         + ",gil:" + to_string(gil)
//         // + "," + bag->toString()
//         + ",knight_type:" + typeString[knightType]
//         + "]";
//     return s;
// }


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
        this->bag = new PaladinBag(this, phoenixdownI, antidote);
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
        this->bag = new LancelotBag(this, phoenixdownI, antidote);
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
        this->bag = new DragonBag(this, phoenixdownI, antidote);
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
        this->bag = new NormalBag(this, phoenixdownI, antidote);
        this->knightType = NORMAL;
    }

    void fight(BaseOpponent* opponent) override {
        // implement fight method for NormalKnight
        return BaseKnight::fight(opponent);
    }
};

BaseKnight *BaseKnight::create(int id, int hp, int level, int gil, int antidote, int phoenixdownI){
    int type = HPtype(hp);
        switch (type){
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

void BaseKnight::fight(BaseOpponent *opponent){
    int levelO = opponent->level;
    if (level > levelO) {
        gil = min(gil + opponent->gil, 999);
    } else {
        hp = hp - opponent->dmg * (levelO - level);
    }
}
/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */
void ArmyKnights::printInfo() const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight * lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}

ArmyKnights::ArmyKnights(const string &file_armyknights) {
    ifstream fin(file_armyknights);
    if (!fin) {
        cerr << "Unable to open input file" << endl;
        exit(EXIT_FAILURE);
    }

    // read first line
    int n;
    if (!(fin >> n)) {
        cerr << "Error reading first line from input file" << endl;
        exit(EXIT_FAILURE);
    }

    if (n <= 0 || n > 1000){
        cerr << "Invalid number of knights" << endl;
        exit(EXIT_FAILURE);
    }

    // read the knights' information and create BaseKnight objects
    for (int i = 0; i < n; i++) {
        int hp, level, pd, gil, antidote;
        if (!(fin >> hp >> level >> pd >> gil >> antidote)) {
            cerr << "Error reading knight information from input file" << endl;
            exit(EXIT_FAILURE);
        }
        knights[i] = BaseKnight::create(i+1, hp, level, gil, antidote, pd);
        count_++;
        // Set nextKnight attribute of current knight object
        if (i < n - 1) {
            knights[i]->setNextKnight(knights[i+1]);
        }
    }
}

ArmyKnights::~ArmyKnights() {
    for(int i = 0; i < count_; i++){
        delete knights[i];
    }
}

bool ArmyKnights::fight(BaseOpponent *opponent) {
    // knights[0]->fight(opponent);
    lastKnight()->fight(opponent);
    return false;
}

bool ArmyKnights::adventure(Events *events){
    int n = events->count();
    for (int i = 0; i < n; i++){
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
                BaseOpponent *Bandit = BaseOpponent::create(levelO, 10, 100, Bdit);
                lastKnight()->fight(Bandit);
                delete Bandit;
                break;
            }
            case 3:
            {
                BaseOpponent *LordLupin = BaseOpponent::create(levelO, 10, 100, Lupin);
                lastKnight()->fight(LordLupin);
                delete LordLupin;
                break;
            }
            case 4:
            {
                BaseOpponent *Elf = BaseOpponent::create(levelO, 10, 100, ELF);
                lastKnight()->fight(Elf);
                delete Elf;
                break;
            }
            default:
                break;
        }
        printInfo();
    }
    return false;
}

int ArmyKnights::count() const{
    return count_;
}

BaseKnight *ArmyKnights::lastKnight() const
{
    if (count_ == 0) {
        return nullptr;
    }
    int index = count_ - 1;
    while (!knights[index]){
        index--;
        if (index < 0) {
            // If all Knights have fallen, return nullptr.
            return nullptr;
        }
    }
    return knights[index];
}

bool ArmyKnights::hasPaladinShield() const {
    return false;
}

bool ArmyKnights::hasLancelotSpear() const {
    return false;
}

bool ArmyKnights::hasGuinevereHair() const {
    return false;
}

bool ArmyKnights::hasExcaliburSword() const {
    return false;
}

void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}
/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}

KnightAdventure::~KnightAdventure() {
    delete armyKnights;
}

void KnightAdventure::run()
{
    armyKnights->printInfo();
}
/* * * END implementation of class KnightAdventure * * */

/* * * BEGIN implementation of class Events * * */
Events::Events(const string & file_events){
    ifstream fin(file_events);
    if (!fin) {
        cerr << "Unable to open input file" << endl;
        exit(EXIT_FAILURE);
    }
    fin >> num_events;

    event_codes = new int[num_events];

    for (int i = 0; i < num_events; i++) {
        fin >> event_codes[i];
    }
    fin.close();   
}

Events::~Events() {
    delete[] event_codes;
}

int Events::count() const {
    return num_events;
}

int Events::get(int i) const {
    return event_codes[i];
}
/* * END implementation of class Events * * */

bool BaseItem::canUse(BaseKnight *knight) {
    return false;
}

void BaseItem::use(BaseKnight *knight) {
}