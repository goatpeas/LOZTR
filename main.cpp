#include <iostream>
#include <fstream>
#include <string>
#include "Character.h"
#include "Ganon.h"
#include "Link.h"
#include "Vaati.h"
#include <cstdlib>
#include "SkullKid.h"

using namespace std;

void Battle(string filename);

int main(){
    
    
    char choice = ' ';
    
    string filename;
    

    std::cout << "                                    /@\n"
              << "                     __        __   /\\/ \n"
              << "                    /==\\      /  \\_/\\/   \n"
              << "                  /======\\    \\/\\__ \\__\n"
              << "                /==/\\  /\\==\\    /\\_|__ \\\n"
              << "             /==/    ||    \\=\\ / / / /_/\n"
              << "           /=/    /\\ || /\\   \\=\\/ /     \n"
              << "        /===/   /   \\||/   \\   \\===\\\n"
              << "      /===/   /_________________ \\===\\\n"
              << "   /====/   / |                /  \\====\\\n"
              << " /====/   /   |  _________    /  \\   \\===\\    THE LEGEND OF \n"
              << " /==/   /     | /   /  \\ / / /  __________\\_____      ______       ___\n"
              << "|===| /       |/   /____/ / /   \\   _____ |\\   /      \\   _ \\      \\  \\\n"
              << " \\==\\             /\\   / / /     | |  /= \\| | |        | | \\ \\     / _ \\\n"
              << " \\===\\__    \\    /  \\ / / /   /  | | /===/  | |        | |  \\ \\   / / \\ \\\n"
              << "   \\==\\ \\    \\\\ /____/   /_\\ //  | |_____/| | |        | |   | | / /___\\ \\\n"
              << "   \\===\\ \\   \\\\\\\\\\\\/   /////// /|  _____ | | |        | |   | | |  ___  |\n"
              << "     \\==\\/     \\\\\\/ / //////   \\| |/==/ \\| | |        | |   | | | /   \\ |\n"
              << "     \\==\\     _ \\/ / /////    _ | |==/     | |        | |  / /  | |   | |\n"
              << "       \\==\\  / \\ / / ///      /|\\| |_____/| | |_____/| | |_/ /   | |   | |\n"
              << "       \\==\\ /   / / /________/ |/_________|/_________|/_____/   /___\\ /___\\\n"
              << "         \\==\\  /               | /==/\n"
              << "         \\=\\  /________________|/=/    TRIFORCE REVERSED!\n"
              << "           \\==\\     _____     /===/\n"
              << "          / \\===\\   \\   /   /===/\n"
              << "         / / /\\===\\  \\_/  /===/\n"
              << "        / / /   \\====\\ /====/\n"
              << "       / / /      \\===|===/\n"
              << "       |/_/         \\===/\n"
              << "                      =\n";


    cout << endl;
    cout << "ASCII art taken from asciiart.eu. Artist's name could not be found." << endl;
    cout << endl;
    
    cout << "Please enter your name to begin: ";
    cin >> filename;
    
    do{
        Battle(filename);
        cout << "Would you like to play again? (y / n):  " ;
        cin >> choice;
    }
    while (choice == 'y');
    
    return 0;
}

void Battle(string filename) {
    
    srand((unsigned)time(NULL));
    bool isalive = true;
    bool exit = false;

    Character* c = nullptr; // pointer for Character player
    Link* target = nullptr; // pointer for opp Link

    ifstream fin(filename);
    
    
    if (fin.is_open()) { // loads your existing data
        char loadChoice;
        cout << "Saved game found. Load saved game? (y/n): ";
        cin >> loadChoice;
        if (loadChoice == 'y') {
            
            string type;
            fin >> type;
            
            if(type == "Ganon"){
                c = new Ganon();
            }
            else if(type == "Vaati"){
                c = new Vaati();
            }
            else if(type == "Skull Kid"){
                c = new SkullKid();
            }
        
            if(c != nullptr){
                c->loadData(filename); // loads whatever character stored in your file
                cout << "Game loaded successfully!" << endl;
            }
        }
        else{
            cout << "Starting a new game." << endl;
            
            cout << "*********************************************************************************" << endl;
            cout << "Select a character: 1. Ganon  2. Vaati  3. Skull Kid" << endl;
            cout << "*********************************************************************************" << endl;

            int charChoice = 0;
            cin >> charChoice;

            // just some clean up in case there's an existing character
            if (c != nullptr) {
                delete c;
                c = nullptr;
            }

            // dynamically dishing out the character type
            while (c == nullptr) {
                switch (charChoice) {
                    case 1:
                        c = new Ganon();
                        break;
                    case 2:
                        c = new Vaati();
                        break;
                    case 3:
                        c = new SkullKid();
                        break;
                    default:
                        cout << "Invalid choice. Please select again: 1. Ganon  2. Vaati  3. Skull Kid" << endl;
                        cin >> charChoice;
                        continue;
                }
            }
        
        // easter egg!!!!!!!
            if(filename == "Zelda" && charChoice == 1){
                cout << "*********************************************************************************" << endl;
                cout << "You discovered the Triforce of Wisdom!" << endl;
                cout << "Congratulatsion! You have completed the Triforce!" << endl;
                cout << "⋆.𖥔 ݁ ˖. ݁₊ ⊹ . ݁˖ . ݁          ▲        ⋆.𖥔 ݁ ˖. ݁₊ ⊹ . ݁˖ . ݁" << endl;
                cout << "⋆.𖥔 ݁ ˖. ݁₊ ⊹ . ݁˖ . ݁         ▲ ▲       ⋆.𖥔 ݁ ˖. ݁₊ ⊹ . ݁˖ . ݁" << endl;
                cout << "Seize the power of the Triforce! Hyrule will be yours!" << endl;
                
                
            }
        }
        fin.close();
    }
    else{ // encompasses what happens if you have no save data existing
        cout << "No saved game found. Starting a new game." << endl;

        // selecting characters
        cout << "*********************************************************************************" << endl;
        cout << "Select a character: 1. Ganon  2. Vaati  3. Skull Kid" << endl;
        cout << "*********************************************************************************" << endl;

        int charChoice = 0;
        cin >> charChoice;

        // just some clean up in case there's an existing character
        if (c != nullptr) {
            delete c;
            c = nullptr;
        }

        // dynamically dishing out the character type
        while (c == nullptr) {
            switch (charChoice) {
                case 1:
                    c = new Ganon();
                    break;
                case 2:
                    c = new Vaati();
                    break;
                case 3:
                    c = new SkullKid();
                    break;
                default:
                    cout << "Invalid choice. Please select again: 1. Ganon  2. Vaati  3. Skull Kid" << endl;
                    cin >> charChoice;
                    continue;
            }
        }
    
    // easter egg!!!!!!!
        if(filename == "Zelda" && charChoice == 1){
            cout << "*********************************************************************************" << endl;
            cout << "You discovered the Triforce of Wisdom!" << endl;
            cout << "Congratulations! You have completed the Triforce!" << endl;
            cout << "⋆.𖥔 ݁ ˖. ݁₊ ⊹ . ݁˖ . ݁          ▲        ⋆.𖥔 ݁ ˖. ݁₊ ⊹ . ݁˖ . ݁" << endl;
            cout << "⋆.𖥔 ݁ ˖. ݁₊ ⊹ . ݁˖ . ݁         ▲ ▲       ⋆.𖥔 ݁ ˖. ݁₊ ⊹ . ݁˖ . ݁" << endl;
            cout << "Seize the power of the Triforce! Hyrule will be yours!" << endl;
            
            
        }
    }
    // created opp object
        target = new Link();
        
        cout << "*********************************************************************************" << endl;
        cout << "View your character's stats? (y / n):  ";
        char statsChoice;
        cin >> statsChoice;

        if (statsChoice == 'y') {
            cout << "*********************************************************************************" << endl;
            c->printStats();
        }

    // while the user hasn't chosen to exit...
    while (!exit) {
        cout << "*********************************************************************************" << endl;
        cout << "You selected: " << c->getName() << endl;
        cout << "Initiating battle..." << endl;
        cout << "Battle has begun!" << endl;
        cout << "*********************************************************************************" << endl;


        // while the user is still alive..
        while (isalive) {
            bool validChoice = false; // handles when heals < 3 but user stil picks useHeal()
            while (!validChoice) {
                cout << "Your Health: " << c->getHealth() << "       Opp Health: " << target->getHealth() << endl;
                cout << "*********************************************************************************" << endl;
                cout << "Choose what action to take: " << endl;
                cout << "1. Attack" << endl;
                cout << "2. Defend" << endl;
                cout << "3. Heal" << endl;
                cout << "4. Special Move" << endl;
                cout << "5. Exit program" << endl;
                cout << "*********************************************************************************" << endl;

                int actChoice = 0;
                cin >> actChoice;
                cout << "*********************************************************************************" << endl;
                
                switch (actChoice) {
                    case 1:
                        c->attack(*target);
                        validChoice = true;
                        break;

                    case 2:
                        c->defend();
                        validChoice = true;
                        break;

                    case 3:
                        if (c->getHealth() == c->getMaxHealth() || c->getHeals() == 0) {
                            cout << "Cannot heal. Choose another action!" << endl;
                        }
                        else {
                            c->useHeal();
                            validChoice = true;
                        }
                        break;

                    case 4:
                        c->spMove(*target);
                        validChoice = true;
                        break;

                    case 5:
                        exit = true; // calls on the exit boolean
                        validChoice = true;
                        break;

                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        break;
                }
            }

            if (exit) {
                break;
            }

            // opponent turn
            bool targetChoice = false;

            while (!targetChoice) {
                int randChoice = rand() % 3;

                switch (randChoice) {
                    case 0:
                        target->attack(*c);
                        targetChoice = true;
                        break;

                    case 1:
                        target->defend();
                        targetChoice = true;
                        break;

                    case 2:
                        if (target->getHeals() == 0 || target->getHealth() == target->getMaxHealth()) {
                            targetChoice = false;
                        } else {
                            target->useHeal();
                            targetChoice = true;
                        }
                        break;

                    default:
                        targetChoice = false;
                        break;
                }
            }

            c->printDialogue();

            if (target->getHealth() <= 0) {
                isalive = false;
                cout << "*********************************************************************************" << endl;
                cout << "Congratulations, " << filename << "!" << endl;
                cout << "You have defeated the Hero of Time. Hyrule is now in your hands." << endl;
                cout << "*********************************************************************************" << endl;
                c->saveData(filename);
                exit = true;
            } else if (c->getHealth() <= 0) {
                isalive = false;
                cout << "*********************************************************************************" << endl;
                cout << "You lost, " << filename << "..." << endl;
                cout << "Hyrule's Hero still stands." << endl;
                cout << "*********************************************************************************" << endl;
                c->saveData(filename);
                exit = true;
            }
        }
    }

   // cleans up memory
    if (c != nullptr) {
        delete c;
    }
}
