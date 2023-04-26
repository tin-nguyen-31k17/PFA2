#include "knight2.h"

/* * BEGIN implementation of submodules * * */
bool isPrime(int n){
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isPythagoreanTriple(int n){
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
bool BaseBag::insertFirst(BaseItem * item){
    if (size >= maxSize) {
        return false; // Bag is full
    }
    Node* newNode = new Node(item);
    newNode->next = head;
    head = newNode;
    size++;
    return true;
}
BaseItem *BaseBag::get(ItemType itemType){
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

string BaseBag::toString() const
{
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
BaseOpponent *BaseOpponent::create(int id, int level, int dmg, int gil, OpponentType opponentType){
    switch (opponentType)
    {
    case MBear:
        return new MadBear(id, level, dmg, gil, opponentType);
        break;
    case Bdit:
        return new Bandit(id, level, dmg, gil, opponentType);
        break;
    case Lupin:
        return new LordLupin(id, level, dmg, gil, opponentType);
        break;
    case ELF:
        return new Elf(id, level, dmg, gil, opponentType);
        break;
    case TROLL:
        return new Troll(id, level, dmg, gil, opponentType);
        break;
    case Tbery:
        return new Tornbery(id, level, dmg, gil, opponentType);
        break;
    case QCards:
        return new QueenOfCards(id, level, dmg, gil, opponentType);
        break;
    case NRings:
        return new NinaDeRings(id, level, dmg, gil, opponentType);
        break;
    case DGarden:
        return new DurianGarden(id, level, dmg, gil, opponentType);
        break;
    case OWeapon:
        return new OmegaWeapon(id, level, dmg, gil, opponentType);
        break;
    case HADES:
        return new Hades(id, level, dmg, gil, opponentType);
        break;
    default:
        break;
    }
    return nullptr;
}

/* * * BEGIN implementation of class BaseKnight * * */
string BaseKnight::toString() const {
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id) 
        + ",hp:" + to_string(hp) 
        + ",maxhp:" + to_string(maxhp)
        + ",level:" + to_string(level)
        + ",gil:" + to_string(gil)
        + "," + bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
}

BaseKnight *BaseKnight::create(int id, int hp, int level, int gil, int antidote, int phoenixdownI){
    int type = HPtype(hp);
        switch (type){
            case -1:
                cout << "Invalid HP type" << endl;
                exit(EXIT_FAILURE);
            case 0:
                return new Paladin(id+1, hp, level, gil, antidote, phoenixdownI);
                break;
            case 1:
                return new Lancelot(id+1, hp, level, gil, antidote, phoenixdownI);
                break;
            case 2:
                return new DragonKnight(id+1, hp, level, gil, antidote, phoenixdownI);
                break;
            case 3:
                return new NormalKnight(id+1, hp, level, gil, antidote, phoenixdownI);
                break;
            case 4:
                cout << "Invalid logic" << endl;
                break;
            default:
                break;
        }
    return nullptr;
}
/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class BaseItem * * */
class Antidote : public BaseItem {
public:
    virtual bool canUse(BaseKnight* knight) {
        return knight->isPoisoned;
    }

    virtual void use(BaseKnight* knight) {
        knight->curePoison();
    }
};

class PhoenixDownI : public BaseItem {
public:
    virtual bool canUse(BaseKnight* knight) {
        return knight->getCurrentHP() <= 0;
    }

    virtual void use(BaseKnight* knight) {
        knight->restoreHP(knight->getMaxHP());
    }
};

class PhoenixDownII : public BaseItem {
public:
    virtual bool canUse(BaseKnight* knight) {
        return knight->getCurrentHP() < knight->getMaxHP() / 4;
    }

    virtual void use(BaseKnight* knight) {
        knight->restoreHP(knight->getMaxHP());
    }
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
};
/* * * END implementation of class BaseItem * * */

/* * * BEGIN implementation of class Knight's Bag * * */
class DragonKnightBag : public BaseBag {
public:
    DragonKnightBag(BaseKnight* knight) : BaseBag(knight, 14) {
        insertFirst(new PhoenixDownI());
        insertFirst(new PhoenixDownII());
        insertFirst(new PhoenixDownIII());
        insertFirst(new PhoenixDownIV());
        insertFirst(new Antidote());
    }
    string toString() const override {
        return BaseBag::toString();   
    }
};

class LancelotBag : public BaseBag {
public:
    LancelotBag(BaseKnight* knight) : BaseBag(knight, 16) {
        insertFirst(new PhoenixDownI());
        insertFirst(new PhoenixDownII());
        insertFirst(new PhoenixDownIII());
        insertFirst(new PhoenixDownIV());
        insertFirst(new Antidote());
    }
    string toString() const override {
        return BaseBag::toString();   
    }
};

class NormalBag : public BaseBag {
public:
    NormalBag(BaseKnight* knight) : BaseBag(knight, 19) {
        insertFirst(new PhoenixDownI());
        insertFirst(new PhoenixDownII());
        insertFirst(new PhoenixDownIII());
        insertFirst(new PhoenixDownIV());
        insertFirst(new Antidote());
    }
    string toString() const override {
        return BaseBag::toString();   
    }
};

class PaladinBag : public BaseBag {
public:
    PaladinBag(BaseKnight* knight) : BaseBag(knight, 1000) {
        insertFirst(new PhoenixDownI());
        insertFirst(new PhoenixDownII());
        insertFirst(new PhoenixDownIII());
        insertFirst(new PhoenixDownIV());
        insertFirst(new Antidote());
    }
    string toString() const override {
        return BaseBag::toString();   
    }
};
/* * * END implementation of class Knight's Bag * * */

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
    }
}

ArmyKnights::~ArmyKnights() {
    for(int i = 0; i < count_; i++){
        delete knights[i];
    }
}

bool ArmyKnights::fight(BaseOpponent *opponent)
{
    // knights[0]->fight(opponent);
    lastKnight()->fight(opponent);
    return false;
}

bool ArmyKnights::adventure(Events *events){
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

bool ArmyKnights::hasPaladinShield() const
{
    return false;
}

bool ArmyKnights::hasLancelotSpear() const
{
    return false;
}

bool ArmyKnights::hasGuinevereHair() const
{
    return false;
}

bool ArmyKnights::hasExcaliburSword() const
{
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

Events::~Events(){
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