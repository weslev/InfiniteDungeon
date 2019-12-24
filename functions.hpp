#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "Player.hpp"
#include "Monster.hpp"
#include <ctime>

bool battle(Player& user, Monster& enemy);
void postBattle(Player& user);

#endif