#include "Vaati.h"
// special moves

void Vaati::divineLightning(Character& target){
    
    // check if enough mana (7) available
    if(mana >= 7){
        
        // add attack from random between 7-10
        srand((unsigned) time(NULL));
        int addAtk = 7 + rand() % 10;
        int damage = atk + addAtk;
        mana -= 7;
        exp += damage;
        // attack link using new damage value
        cout << "Vaati used Divine Lightning! It dealt " << damage << " damage!" << endl;
        cout << mana << " mana remaining." << endl;
        target.takeDamage(damage);
    }
    // if mana is not available..
    else{
        cout << "Not enough mana!" << endl;
        // has to loop back to choices if you don't have enough menu. how?
    }
}

void Vaati::amethystShield(){
    
    // random def value from 1-4
    if(mana >= 3){
        srand((unsigned) time(NULL));
        int addDef = 1 + rand() % 4;
        def += addDef;
        mana -= 3;
        cout << "Vaati used Amethyst Shield! DEF boosted by " << addDef << " !" << endl;
    }
    else{
        cout << "Not enough mana!" << endl;
    }
    
}

// sp

int Vaati::getUserChoice(){
    
    cout << "Choose a special move (1 or 2): " << endl;
    cout << "1. Divine Lightning (dmg UP by 7-20, costs 4 mana)" << endl;
    cout << "2. Amethyst Shield (def UP by 4-6, costs 2 mana)" << endl;
    
    int choice;
    cin >> choice;
    
    if(choice > 2 || choice <= 0){
        cout << "Invalid choice, retry." << endl;
        return 0;
    }
    
    return choice;
}


void Vaati::spMove(Character& target) {
    int choice = getUserChoice();
    if (choice == 1) {
        divineLightning(target);
    }
    else if (choice == 2) {
        amethystShield();
        defend();
    }
}
    

// this works
void Vaati::printStats(){

    cout << "Character: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Health: " << health << "/" << maxHealth << endl;
    cout << "Attack: " << atk << endl;
    cout << "Defense: " << def << endl;
    cout << "Mana: " << mana << "/" << maxMana << endl;
    cout << "EXP: " << exp << "/" << expNextLvl << endl;

}

void Vaati::attack(Character& target){
    srand((unsigned) time(NULL));
    int damage = 0;
    
    damage = 15 + rand() % (20 - 15 + 1);
    cout << "Vaati attacked! Dealt " << damage << " damage!" << endl;

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
void Vaati::resetDefense() {
    def = baseDef;
}

void Vaati::defend() { // there's no point to the opponent even being here
    defending = true;
    cout << name << " is defending!" << endl;
}

void Vaati::stopDefending(){
    defending = false;
    cout << name << " stopped defending." << endl;
}

bool Vaati::isDefending(){
    return defending;
}


void Vaati::useHeal(){
    if(heals > 0){
        int addHealth = 10 + rand() % (15 - 10 + 1);
        cout << "Vaati drained the Light Force! Restored " << addHealth << " health!" << endl;
        health += addHealth;
        if(health > maxHealth){
            health = maxHealth;
        }
        heals --;
        cout << heals << " drains remaining." << endl;
    }
}

void Vaati::printDialogue(){

    
    int halfHealth = maxHealth / 2;
    
    cout << "*********************************************************************************" << endl;
    if(health <= halfHealth){
        cout << "Vaati: I am a sorcerer now, and my power is beyond comparison! None can stop me..." << endl;
        cout << "*********************************************************************************" << endl;

    }
    else if(health == 0){
        cout << "Vaati: But the Light Force... My power... I had such power...!" << endl;
    }
    
}

void Vaati::lvlUp(){
   
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
    cout << "Dark winds tear through Hyrule!" << endl;
    cout << "Vaati levelled up!" << endl;
    cout << "*********************************************************************************" << endl;
    printStats();
}

