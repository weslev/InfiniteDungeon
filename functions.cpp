#include "functions.hpp"

// Function for the battle between the player and monsters
bool battle(Player& user, Monster& enemy) 
{
    // Variable is used to see if the type of the enemy has been discovered
    bool enemyKnown = false;

    // Enemy's identity
    string identity = "UNKNOWN";

    // For choosing the player's attack
    int attackChoice = -1;

    // The attack data from the player
    tuple<int, type> attackData(0, fire);


    // Loop that runs while the enemy is still alive
    while(enemy.getStatus()) 
    {
        // gives player's and enemy's current stats
        cout << "Your health is: " << user.getHP();
        cout << " and your mana is: " << user.getMana() << endl;
        cout << "Your enemy's health is " << enemy.getHP() << endl;
        cout << "Your enemy's type is: ";

        // tells player the enemy type if known
        if (enemyKnown) {  identity = arrayType[enemy.getType()]; } 

        // Prints the identity
        cout << identity << endl;

        cout << "\n\n";
        
        // Gets user attack choice
        cout << "How do you attack the monster?" << endl;
        cout << "1 basic, 2 fire, 3 water, 4 earth" << endl;
        cin >>  attackChoice;

        // If they choose a basic attack
        if (attackChoice == 1) { attackData = user.basicAttack(); }
        
        // If they choose a fire attack
        else if (attackChoice == 2) { attackData = user.fireAttack(); }

        // If they choose a water attack
        else if (attackChoice == 3) { attackData = user.waterAttack(); }
        
        // If they choose an earth attack
        else if (attackChoice == 4) { attackData = user.earthAttack(); }

        // enemy takes damage and checks if the enemy type is discovered
        enemyKnown = enemy.takeDamage(attackData);

        // If the enemy has health below 0
        if(enemy.getHP() <= 0) 
        {   
            // Sets the monster to defeated and informs the player
            cout << "You have defeated the monster!" << endl;
            enemy.setStatus(false);
            continue;
        }

        cout << "\nEnemy is attacking!\n" << endl;

        // Gets an attack from the enemy and damages the player
        user.takeDamage(enemy.attackSelect());

        // If the player's health is below 0
        if(user.getHP() <= 0) 
        {   
            // Sets the user to defeated and informs the player of the defeat
            cout << "You were defeated!" << endl;
            user.setStatus(false);
            // Returns false, which will be used to end the game
            return false;
        }
        
    }

    // Returns true for battles won
    return true;
}

// Function for the post battle shop
void postBattle(Player& user)
{
    // Post battle title screen
    cout << "\nWelcome to the post battle shop!" << endl;
    cout << "Here you can choose to fully heal or partially heal ";
    cout << "and recharge your mana." << endl;

    // Prompts the user for their choice
    int choice = 0;

    // Runs until the player inputs a valid integer
    while(true) 
    {
        // Prints possible choices
        cout << "What would you like to do?" << endl;
        cout << "1. to fully heal" << endl;
        cout << "2. to partially heal and fully recharge mana" << endl;
        cin >> choice;

        // If the player chooses 1
        if(choice == 1) 
        {
            // Heals the player fully
            int health = user.getHealth();
            int increaseHP = 100 - health;
            user.heal(increaseHP);
            break;
        }

        // If the player chooses 2
        else if(choice == 2) 
        {
            // Heals the player by half of their current health
            int health = user.getHealth();
            int increaseHP = health / 2;
            user.heal(increaseHP);

            // Fully restores the player's mana
            int mana = user.getMP();
            int manaIncrease = 100 - mana;
            user.manaRestore(manaIncrease);
            break;
        }

        // If the player enters a bad input
        else 
        {
            // Brings them back to the beginning of the selection loop
            cout << "\nBad input, try again." << endl;
            continue;
        }
    }
}