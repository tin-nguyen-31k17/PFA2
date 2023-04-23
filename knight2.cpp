#include "knight2.h"

/* * * BEGIN implementation of class BaseBag * * */
bool BaseBag::insertFirst(BaseItem * item){
    return false;
}

BaseItem *BaseBag::get(ItemType itemType)
{
    return nullptr;
}

string BaseBag::toString() const
{
    return string();
}
/* * * END implementation of class BaseBag * * */

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

BaseKnight *BaseKnight::create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
{
    return nullptr;
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
    }
}

ArmyKnights::~ArmyKnights()
{
}

bool ArmyKnights::fight(BaseOpponent *opponent)
{
    // knights[0]->fight(opponent);
    return false;
}

bool ArmyKnights::adventure(Events *events)
{
    return false;
}

int ArmyKnights::count() const
{
    return 0;
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