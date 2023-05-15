#include "knight2.h"
#include <iostream>
#include <sstream>

int main(int argc, char ** argv) {
    for (int i = 1; i <= 1000; i++) {
        std::stringstream ss;
        ss << "testcase_" << i << "_knights.txt";
        cout << "testcase_" << i << "_knights.txt" << endl;
        std::string file_armyknights = ss.str();
        ss.str(std::string()); // Clear the stringstream
        ss << "testcase_" << i << "_events.txt";
        std::string file_events = ss.str();

        // BEGIN
        KnightAdventure * knightAdventure = new KnightAdventure();
        knightAdventure->loadArmyKnights(file_armyknights);
        knightAdventure->loadEvents(file_events);
        knightAdventure->run();

        delete knightAdventure;
    }

    return 0;
}
