#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>

using namespace std;

// Constant that contains all the possible enemy/attack types
const string arrayType[] = {"fire", "water", "earth", "basic"};

// Enumeration of all the possible enemy/attack types
enum type {fire, water, earth, basic};

// Character class that is inherited by both the Player and Monster classes
class Character 
{
    private:
        int health;
        int mana;
        bool alive;
    public:
        Character();
        Character(int, int);
        void setHealth(int);
        void setMana(int);
        void setAlive(bool);
        int getHealth();
        int getMana();
        bool getAlive();
};

#endif