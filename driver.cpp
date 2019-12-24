#include "Player.hpp"
#include "Monster.hpp"
#include "functions.hpp"
#include <fstream>
#include <string>

// TODO fix healing system
// TODO improve the score system
// TODO add a main menu

/*
| Main function includes the file output (work in progress)
| and the main game loop.
| The main game loop contains the calls
| to each battle and the post battle shop.
*/
int main() 
{
    // TODO finish scores system
    // Output file holds all the saved scores
    //ofstream scores("scores.txt", ios::app);
    
    // Name is written to the file next to the number of wins
    //string name;

    // Object that represents the player
    Player user;

    // Tracks the number of monsters defeated
    int wins = 0;

    // Game loop, only breaks if the playere loses a battle
    while(true) 
    {
        // A new Monster instance is created before each battle
        Monster enemy;

        // Battle function is called passing in the Player and Monster objects
        // Returns true if the player wins the battle
        if(battle(user, enemy)) 
        {
            // wins is incremented for each victory
            wins++;
        } 

        // If the player loses the battle, a defeat message is displayed
        // and the game loop is broken
        else 
        {
            cout << "Looks like you lost that battle!" << endl;
            cout << "You won " << wins << " battle(s)! ";
            cout << "That's good!" << endl;
            break;
        }

        // The post battle shop is called.
        // Here the player can choose how to heal
        postBattle(user);
    }

    // TODO score system needs to be refined
    /*
    // Prompts the user to give their name for scores file
    cout << "Enter your name to save to scores" << endl;

    // Catches new line character
    cin.ignore();

    // Gets the name
    getline(cin, name);

    // Outputs the organized data to the file
    scores << name << " won: " << wins << " rounds." << endl;
    scores.close();
    */

    // Program ends here
    cout << "Thanks for playing!" << endl;
    return 0;
}