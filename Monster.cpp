#include "Monster.hpp"

// Monster default constructor
Monster::Monster() : Character(100,100) 
{
    // Seeds the random number
    srand(time(NULL));

    // Gets a random number for selecting the type of monster
    int selection = rand() % 3;

    // Sets the monsterType to the random type
    this->monsterType = static_cast<type>(selection);
}


// Monster regular constructor
Monster::Monster(type monster) : Character(100,100) 
{   
    // Sets monsterType to the monster parameter
    this->monsterType = monster;
}

// Status getter
bool Monster::getStatus() 
{
    return getAlive();
}

// HP getter
int Monster::getHP() 
{
    return getHealth();
}

// monsterType getter
type Monster::getType() 
{
    return monsterType;
}

// status setter
void Monster::setStatus(bool isAlive) 
{
    setAlive(isAlive);
}

// For the special attack of the enemy
int Monster::specialAttack() 
{
    // Attack variable for the attack damage
    int attack = 0;

    // If the monster has greater than 0 mana
    if (getMana() > 0) 
    {
        //Gets a random amount of damage
        srand(time(NULL));
        attack = rand() % 40 + 10;

        // Uses monster's mana
        setMana(getMana() - 25);
    }

    // If the monster is out of mana
    else 
    {
        // Gets a random amount of damage
        attack = rand() % 30;
    }

    // Returns the damage
    return attack;
}

// For the basic enemy attack
int Monster::basicAttack() 
{
    // Gets a random amount of damage
    srand(time(NULL));
    int attack = rand() % 20;

    // Returns the damage
    return attack;
}


// For when the monster takes damage
bool Monster::takeDamage(tuple<int, type> damageData) 
{
    // Gets the current health
    int currentHealth = getHealth();

    // If the attack type is the same type as the monster
    // the attack will not be very effective
    if(getType() == get<1>(damageData)) 
    {
        // Informs the player of the effectiveness and monsterType
        cout << "That move was not very effective because the enemy is a ";
        cout << arrayType[getType()] << " monster!" << endl;

        // Deals the damage to the enemy
        currentHealth -= (get<0>(damageData) - 10);
        setHealth(currentHealth);

        // Returns true that the monster's identity has been discovered
        return true;
    }
    // If the attack type is water and the monster type is fire
    // the attack will be very effective
    else if (getType() == fire && get<1>(damageData) == water)
    {
        // Informs the player of the effectiveness and monsterType
        cout << "That move was very effective because the enemy is a ";
        cout << arrayType[getType()] << " monster!" << endl;

        // Deals the damage to the enemy
        currentHealth -= (get<0>(damageData) + 15);
        setHealth(currentHealth);

        // Returns true that the monster's identity has been discovered
        return true;
    }
    // If the attack type is water and the monster typ is earth
    else if (getType() == water && get<1>(damageData) == earth)
    {
        // Informs the player of the effectiveness and monsterType
        cout << "That move was very effective because the enemy is a ";
        cout << arrayType[getType()] << " monster!" << endl;

        // Deals the damage to the enemy
        currentHealth -= (get<0>(damageData) + 15);
        setHealth(currentHealth);

        // Returns true that the monster's identity has been discovered
        return true;
    }

    // If the attack type is fire and the monster type is earth
    else if (getType() == earth && get<1>(damageData) == fire)
    {
        // Informs the player of the effectiveness and monsterType
        cout << "That move was very effective because the enemy is an ";
        cout << arrayType[getType()] << " monster!" << endl;

        // Deals the damage to the enemy
        currentHealth -= (get<0>(damageData) + 15);
        setHealth(currentHealth);

        // Returns true that the monster's identity has been discovered
        return true;
    }

    // If the attack is not a weakness nor the same type as the monster
    else 
    {
        // Deals the damage to the enemy
        currentHealth -= get<0>(damageData);
        setHealth(currentHealth);

        // Returns true that the monster's identity has been discovered
        return false;
    }

    return false;
}

// Function for selecting the monster's attack
int Monster::attackSelect() 
{
    // Random number generated
    srand(time(NULL));
    int choice = rand() % 100;

    // Will most likely return a basic attack
    if (choice < 75) 
    { 
        return basicAttack(); 
    }
    
    // If a basic attack is not returned, a special attack is returned
    return specialAttack();
}