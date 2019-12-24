#include "Player.hpp"


// Player default constructor
Player::Player() : Character(100, 100) {};


// Status setter
void Player::setStatus(bool value) 
{
    setAlive(value);
}

// HP getter
int Player::getHP() 
{
    return getHealth();
}

// MP getter
int Player::getMP() 
{
    return getMana();
}

// Status getter
bool Player::getStatus() 
{
    return getAlive();
}

// Function for taking damage in battle
void Player::takeDamage(int damage) 
{
    //Gets the current health
    int currentHealth = getHealth();
    
    // Subtracts the damage taken
    currentHealth -= damage;
    
    // Sets health to the current health minus the damage
    setHealth(currentHealth);
}

// Function for healing the player
void Player::heal(int healing) 
{
    // Gets the current health
    int currentHealth = getHealth();

    // Adds the amount of healing
    currentHealth += healing;

    // Sets health to the current health plus the healing
    setHealth(currentHealth);
}

// Function for using mana
void Player::useMana(int power) 
{
    // Gets the current mana
    int currentMana = getMana();

    // Subtracts the amount of mana used
    currentMana -= power;

    // Sets the current mana to the mana minus the amount used
    setMana(currentMana);
}

// Function for restoring mana
void Player::manaRestore(int power) 
{
    // Gets the current mana
    int currentMana = getMana();

    // Adds the amount of mana restored
    currentMana += power;

    // Sets the current mana to the mana plus the amount added
    setMana(currentMana);
}

// Function for a basic attack
tuple<int,type> Player::basicAttack() 
{
    // Makes a attack tuple of random damage and of type basic
    srand(time(NULL));
    tuple<int,type> attack((rand() % 20), basic);

    // Returns the attack
    return attack;
}

// Function for a fire attack
tuple<int, type> Player::fireAttack() 
{ 
    // Creates a tuple of fire type
    tuple<int, type> attack(0, fire);
    
    // If the player has greater than 0 mana
    if (getMana() > 0) 
    {
        // Gets random damage and saves it to the tuple
        srand(time(NULL));
        get<0>(attack) = rand() % 40 + 10;

        // Uses mana
        useMana(25);
    }

    // If the player is out of mana, gets a weak attack
    else 
    {
        cout << "You're out of mana! The attack is quite weak..." << endl;
        get<0>(attack) = rand() % 20;
    }

    // Returns the attack
    return attack;
}


// Function for a water attack
tuple<int, type> Player::waterAttack() 
{   
    // Creates a tuple of water type
    tuple<int, type> attack(0, water);
    
    // If the player has greater than 0 mana
    if (getMana() > 0) 
    {
        // Gets the random damage and saves it to the tuple
        srand(time(NULL));
        get<0>(attack) = rand() % 40 + 10;

        // Uses mana
        useMana(25);
    }

    // If the player is out of mana, gets a weak attack
    else
    {
        cout << "You're out of mana! This move was not very effective..." << endl;
        get<0>(attack) = rand() % 10;
    }

    // Returns the attack
    return attack;
}

// Function for a earth attack
tuple<int, type> Player::earthAttack() 
{

    // Creates a tuple of earth type
    tuple<int, type> attack(0, earth);
    
    // If the player has greater than 0 mana
    if (getMana() > 0) 
    {
        // Gets the random damage and saves it to the tuple
        srand(time(NULL));
        get<0>(attack) = rand() % 40 + 10;

        // Uses mana
        useMana(25);
    }

    // If the player is out of mana, gets a weak attack
    else 
    {
        cout << "You're out of mana! This move was not very effective..." << endl;
        get<0>(attack) = rand() % 10;
    }

    // Returns the attack
    return attack;
}
