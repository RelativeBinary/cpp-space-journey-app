#ifndef spaceship_h
#define spaceship_h
#include <iostream>
#include <string>
#include <vector>
#include "SpaceSector.h"
#include "Officer.h"

class SpaceShip //COMPLETE
{
    /* 
        Core Stats: based on shiptype OR rng based on race. (strength, health, shield, armour, fuel, food, agility, speed, resources, money)
        Ability Stats: based on officer skill and rank OR rng based on race for non-player ships.
    */
    protected:
        int strength;
        int health;
        int shield;
        int armour;//"bonus" health protects officers
        int fuel;
        int food;
        int agility;
        int speed;
        int resources;
        int money;
        int lowmin = 0;
        int lowmax = 40;
        int midmin = 41;
        int midmax = 70;
        int highmin = 71;
        int highmax = 100;
    public:
        /*
            raising any stats should only occur through the abilities that 
            are availble to use on the ship e.g. attempSystemRecovery is the only way
            to raise health, shields and armour.  
        */
        SpaceShip();
        #pragma region
        int getStrength();
        int getHealth();
        int getShield();
        int getArmour();
        int getFuel();
        int getFood();
        int getAgility();
        int getSpeed();
        int getResources();
        int getMoney();
        #pragma endregion 
    private:
};

class SpaceShipEncounter : public SpaceShip, public SpaceSector //INCOMPLETE
{
public:
    SpaceShipEncounter();
private:
    void solarisShipSetup();
    void scarShipSetup();
    void celestialShipSetup();
    void galvamekShipSetup();
    void humanShipSetup();

};

class Playership : public SpaceShip //INCOMPLETE
{
    /* 
        Core Stats: based on rng and shipType(strength, health, shield, armour, fuel, food, agility, speed, resources, money, crew, cargoCapacity, miningPower, fuelEfficiency)
        Ability Stats: based on officier skill level and rank
    */
    int crew;
    int cargoCapacity;
    int miningPower;
    int fuelEfficiency;
    int diplomacyLevel; 
    int tradabilityLevel; 
    int travelEfficiencyLevel;
    int combatManuverabilityLevel;
    int evasionAbilityLevel;
    int defesiveAbilityLevel;
    int systemsRecoveryLevel;
    int miningAbilityLevel;
    int offensiveAbilityLevel;
    std::string shipType;
    std::vector<Officer> officers;
public:
    Playership();
    Playership(std::vector<Officer> officers);
    Playership(std::string type, std::vector<Officer> officers);
    int getCrew();
    int getCargoCapacity();
    int getminingPower();
    int getfuelEfficiency();
    std::string getShipType();
    std::vector<Officer> getOfficers(Officer newOfficer);
    //TODO: Make sure all abilities are being defined here
    void useTrade(SpaceSector &trader);     //use captain, rng chance of success
    void useSystemsRecovery();               //use engineer, activates on travel
    bool useDiplomacy(SpaceSector &aggressor); //use captain, targets diplomacy stat, check skillevel, rng chance of success
    bool useTravel();                        //use pilot, engineer, attempSystemsRecovery(),
    bool useCombatMauver(SpaceShipEncounter &attacker); //use pilot, engineer, takes attackers combat manuver and offensive performance stat
    bool useEscape(SpaceShipEncounter &attack);         //use engineer, pilot, speed, agility, takes attacker's speed
    void useMine(PlanetEncounter &target);   //use miner stats.
    bool useAttack(SpaceShipEncounter &target); //uses weaponsSmith and pilot, takes targets defensive stats.
    bool takeDamageFrom(SpaceShipEncounter &attacker);
private:
    void reallocateDefense(); //use weaponsSmith and engineer, occurs on initialisation and if the either the weaponsSmith dies or an Engineer dies.
    void setupShip();
    void OffensiveSetup();
    void MinerSetup();
    void DefensiveSetup();
    void OneHitSetup();
    void AverageSetup();
    Officer findOfficer(std::string job);
    void checkForDead();
    void addToCrew();                       //chance to pick up crew members from planets, ships and trading stations.
    void damageCrew();                      //chance to kill crew members
    int addOfficer(Officer newOfficer);     //in the case of an officer being replaced
    //some sort of create new officer function which find the LAST officer to have died in that job.
    void checkFood();
    bool hasFuel();
};

#endif
