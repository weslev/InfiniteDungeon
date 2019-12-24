#ifndef MONSTER_HPP
#define MONSTER_HPP

#include "Character.hpp"
#include <cstdlib>
#include <tuple>

// Monster class that represents the enemies
class Monster : public Character 
{
    private:
        type monsterType;
    public:

        // Monster settings
        Monster();
        Monster(type);
        bool getStatus();
        int getHP();
        type getType();
        void setStatus(bool);

        // Gameplay mechanics
        int specialAttack();
        int basicAttack();
        bool takeDamage(tuple<int, type>);
        int attackSelect();
};

#endif