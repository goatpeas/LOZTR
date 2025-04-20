#include "Ganon.h"
// special moves

void Ganon::warlockPunch(Character& target){
    
    // check if enough mana (7) available
    if(mana >= 7){
        
        // add attack from random between 7-10
        srand((unsigned) time(NULL));
        int addAtk = 7 + rand() % 10;
        int damage = atk + addAtk;
        mana -= 7;
        exp += damage;
        // attack link using new damage value
        cout << "Ganon used Warlock Punch! It dealt " << damage << " damage!" << endl;
        cout << mana << " mana remaining." << endl;
        target.takeDamage(damage);
    }
    // if mana is not available..
    else{
        cout << "Not enough mana!" << endl;
        // has to loop back to choices if you don't have enough menu. how?
    }
}

void Ganon::demonShield(){
    
    // random def value from 1-4
    if(mana >= 3){
        srand((unsigned) time(NULL));
        int addDef = 1 + rand() % 4;
        def += addDef;
        mana -= 3;
    }
    else{
        cout << "Not enough mana!" << endl;
    }
    
}

// sp

int Ganon::getUserChoice(){
    
    cout << "Choose a special move (1 or 2): " << endl;
    cout << "1. Warlock Punch (dmg UP by 7-10, costs 7 mana)" << endl;
    cout << "2. Demon Shield (def UP by 1-3, costs 3 mana)" << endl;
    
    int choice;
    cin >> choice;
    
    if(choice > 2 || choice <= 0){
        cout << "Invalid choice, retry." << endl;
        return 0;
    }
    
    return choice;
}


void Ganon::spMove(Character& target) {
    int choice = getUserChoice();
    if (choice == 1) {
        warlockPunch(target); // apply attack to the target
    }
    else if (choice == 2) {
        demonShield();
        defend();
    }
}
    

// this works
void Ganon::printStats(){

    cout << "Character: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Health: " << health << "/" << maxHealth << endl;
    cout << "Attack: " << atk << endl;
    cout << "Defense: " << def << endl;
    cout << "Mana: " << mana << "/" << maxMana << endl;
    cout << "EXP: " << exp << "/" << expNextLvl << endl;

}

void Ganon::attack(Character& target){
    srand((unsigned) time(NULL));
    int damage = 0;
    
    damage = 15 + rand() % (20 - 15 + 1);
    cout << "Ganon attacked! Dealt " << damage << " damage!" << endl;

    if(target.isDefending()){
        damage = std::max(1, damage - target.getDef() / 2);
        cout << target.getName() << " resisted! Took " << damage << " damage!" << endl;
        target.takeDamage(damage);
        target.stopDefending();
        target.resetDefense();
    }
    else{
        damage = std::max(0, damage);
        target.takeDamage(damage);
    }
    mana = maxMana;
    gainExp(damage);
    
}

// defending
void Ganon::resetDefense() {
    def = baseDef;
}

void Ganon::defend() { 
    defending = true;
    cout << name << " is defending!" << endl;
}

void Ganon::stopDefending(){
    defending = false;
    cout << name << " stopped defending." << endl;
}

bool Ganon::isDefending(){
    return defending;
}


void Ganon::useHeal(){
    if(heals > 0){
        int addHealth = 10 + rand() % (15 - 10 + 1);
        cout << "Ganon ate the flesh of his subjects! Restored " << addHealth << " health!" << endl;
        health += addHealth;
        if(health > maxHealth){
            health = maxHealth;
        }
        heals --;
        cout << heals << " minions left to devour." << endl;
    }
}

void Ganon::printDialogue(){
    
    int halfHealth = maxHealth / 2;
    
    cout << "*********************************************************************************" << endl;
    if(health <= halfHealth){
        cout << "Ganon: Pathetic little fool! Do you realize who you're dealing with? " << endl;
        cout << "I am Ganondorf! And soon, I will rule the world!" << endl;
        cout << "*********************************************************************************" << endl;

      }
      else if (health == 0) {
          cout << "Ganon: Do not think that this ends here... the history of light and shadow will be written in blood!" << endl;
      }
}

void Ganon::lvlUp(){
   
    level ++;
    exp -= expNextLvl;
    expNextLvl *= 2;

    // update stats
    health = maxHealth;
    maxHealth += 12;
    atk += 4;
    def += 2;
    maxMana += 1;

    cout << "*********************************************************************************" << endl;
    cout << "The Blood Moon rises over Hyrule!" << endl;
    cout << "Ganon levelled up!" << endl;
    cout << "*********************************************************************************" << endl;
    printStats();

}
