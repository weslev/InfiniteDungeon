#include "Character.hpp"

// Character default constructor
Character::Character() 
{
    // sets health to 100
    this->health = 100;
    //  sets mana to 100
    this->mana = 100;
    // sets alive to true
    this->alive = true;
}

//  Regular character constructor
Character::Character(int hp, int mp) 
{
    // Sets health to the hp parameter
    this->health = hp;
    // Sets mana to the mp parameter
    this->mana = mp;
    // Sets alive to true
    this->alive = true;
}

// health setter
void Character::setHealth(int hp) 
{
    this->health = hp;
}

// mana setter
void Character::setMana(int mp) 
{
    this->mana = mp;
}

// alive setter
void Character::setAlive(bool status) 
{
    this->alive = status;
}

// health getter
int Character::getHealth() 
{
    return this->health;
}

// mana getter
int Character::getMana() 
{
    return this->mana;
}

// alive getter
bool Character::getAlive() 
{
    return this->alive;
}