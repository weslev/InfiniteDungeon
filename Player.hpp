#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <cstdlib>
#include <tuple>
#include "Character.hpp"

using namespace std;

// Player class that will represent the user
class Player : public Character 
{
    public:
        
        // Basic player settings
        Player();
        void setScore(int);
        void setLevel(int);
        void setStatus(bool);
        int getScore();
        int getLevel();
        int getHP();
        int getMP();
        bool getStatus();


        // Gameplay mechanics
        void takeDamage(int);
        void heal(int);
        void useMana(int);
        void manaRestore(int);
        tuple<int,type> fireAttack();
        tuple<int,type> waterAttack();
        tuple<int,type> earthAttack();
        tuple<int,type> basicAttack();
};
#endif