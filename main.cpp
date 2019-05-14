#include "functions.h"
#include "Officer.h"
#include "SpaceShip.h"
#include "SpaceSector.h"
#include <time.h>

int SpaceSector::sectorCount = 0;

int main(int argc, char* argv[]){
    std::srand(time(NULL));
    std::cout << "Charging Partical Accellerators.." << '\n';
    std::cout << '\n';
    std::cout << "Lauching The Space Journey" << '\n';
    //take cli args
    const int limit = std::atoi(argv[1]);
    std::cout << "Targeting " << limit << " sectors from initializtion point" << '\n';

    //initialize spaceship

    //initialize officiers and skill stats

    std::vector<Officer> officers;

    #pragma region //Officer Test Code
    //Officer function testing
    //Stage one - no rng, testing function effects: testing complete, outputs OK, logic OK, non-rng testing completed
    //Stage two - rng, testing function effects:
    Officer f1("captain", randNumGen(50,100));
    Officer f2("pilot", randNumGen(50, 100));
    Officer f3("engineer", randNumGen(50, 100));
    Officer f4("miner", randNumGen(50, 100));
    Officer f5("weapons", randNumGen(50, 100));
    f1.displayOfficer();
    f1.levelUpSkill(10);
    f1.takeDamage(2000);
    f1.restoreHealth(5);
    f1.displayOfficer();
    officers.push_back(f1);

    f2.displayOfficer();
    officers.push_back(f2);

    f3.displayOfficer();
    officers.push_back(f3);

    f4.displayOfficer();
    officers.push_back(f4);

    f5.displayOfficer();
    officers.push_back(f5);
    std::cout << '\n' << '\n';
    #pragma endregion
    
    #pragma region//SpaceShip Testing
    SpaceShip sh1;
    sh1.displaySpaceShip();
    std::cout << '\n' << '\n';
    #pragma endregion
    
    #pragma region //SpaceShipEncounter Testing
    SpaceShipEncounter she1;
    std::cout << std::endl;
    she1.displaySpaceSector();
    she1.displaySpaceShip();
    std::cout << '\n'<< '\n';
    #pragma endregion
/*
    #pragma region //Playership Testing
    Playership p1(officers);
    p1.displayPlayership();
    std::cout << "Attempting to travel: " << p1.useTravel() << '\n';
    std::cout << "Using diplomacy: " << p1.useDiplomacy(she1) << '\n';
    std::cout << "Using trade: " << "tradStation not setup, also interfaces are needed to prevent sectors which shouldn't be able to trade from trading\n";
    std::cout << "Taking damage: " << p1.takeDamageFrom(she1) << '\n';
    std::cout << "Attemptng to escape: " << p1.useEscape(she1) << '\n';
    std::cout << "Attempting sys recovery: "; 
    p1.useSystemsRecovery();
    std::cout << '\n';
    std::cout << "Attempting mine: " << "not set up\n";
    std::cout << "Attempting to attack: " << p1.useAttack(she1) << '\n';
    std::cout << '\n'<< '\n';
    #pragma endregion

    #pragma region //SpaceSector Testing
    SpaceSector s1;
    s1.displaySpaceSector();
    std::cout << '\n'<< '\n';
    #pragma endregion*/

    return 0;
}