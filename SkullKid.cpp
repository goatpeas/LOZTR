#include "SkullKid.h"

void SkullKid::TimesUp(Character& target){
    
    if(mana >= 5){
        
        // add attack from random between 7-10
        srand((unsigned) time(NULL));
        int addAtk = 7 + rand() % (12 - 7 + 1);
        int damage = atk + addAtk;
        mana -= 5;
        exp += damage;
        
        // attack link using new damage value
        cout << "Skull Kid used Time's Up! It dealt " << damage << " damage!" << endl;
        cout << mana << " mana remaining." << endl;
        target.takeDamage(damage);
    }
    // if mana is not available..
    else{
        cout << "Not enough mana!" << endl;
        // has to loop back to choices if you don't have enough menu. how?
    }
    
}

void SkullKid::majorasMask(){
    
    if(mana >= 2){
        srand((unsigned) time(NULL));
        int addDef = 2 + rand() % (5 - 2 + 1);
        def += addDef;
        mana -= 2;
    }
    else{
        cout << "Not enough mana!" << endl;
    }
}

int SkullKid::getUserChoice(){
    
    cout << "Choose a special move (1 or 2): " << endl;
    cout << "1. Time's Up (dmg UP by 7-12, costs 5 mana)" << endl;
    cout << "2. Majora's Mask (def UP by 2-5, costs 2 mana)" << endl;
    
    int choice;
    cin >> choice;
    
    if(choice > 2 || choice <= 0){
        cout << "Invalid choice, retry." << endl;
        return 0;
    }
    
    return choice;
}

void SkullKid::spMove(Character& target) {
    int choice = getUserChoice();
    if (choice == 1) {
        TimesUp(target);
    }
    else if (choice == 2) {
        majorasMask();
        defend();
    }
}

void SkullKid::attack(Character& target){
    srand((unsigned) time(NULL));
    int damage = 0;
    
    damage = 10 + rand() % (13 - 10 + 1);
    cout << "Skull Kid attacked! Dealt " << damage << " damage!" << endl;

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

void SkullKid::printStats(){

    cout << "Character: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Health: " << health << "/" << maxHealth << endl;
    cout << "Attack: " << atk << endl;
    cout << "Defense: " << def << endl;
    cout << "Mana: " << mana << "/" << maxMana << endl;
    cout << "EXP: " << exp << "/" << expNextLvl << endl;

}

// defending
void SkullKid::resetDefense() {
    def = baseDef;
}

void SkullKid::defend() { // there's no point to the opponent even being here
    defending = true;
    cout << name << " is defending!" << endl;
}

void SkullKid::stopDefending(){
    defending = false;
    cout << name << " stopped defending." << endl;
}

bool SkullKid::isDefending(){
    return defending;
}


void SkullKid::useHeal(){
    if(heals > 0){
        int addHealth = 10 + rand() % (15 - 10 + 1);
        cout << "The fairies healed Skull Kid! Restored " << addHealth << " health!" << endl;
        health += addHealth;
        if(health > maxHealth){
            health = maxHealth;
        }
        heals --;
        cout << heals << " heals left." << endl;
    }
    else if(heals == 0){
        cout << "No more heals!" << endl;
    }
}

void SkullKid::printDialogue(){
    
    // i could change the system so it does this in main and takes in choice as a parameter
    
    int halfHealth = maxHealth / 2;
    
    cout << "*********************************************************************************" << endl;
    if(health <= halfHealth){
        cout << "Tael: Whoa! Don't get reckless, Skull Kid!" << endl;
        cout << "Tatl: Mayday! Mayday! Beat him up, Skull Kid!" << endl;
        cout << "*********************************************************************************" << endl;

    }
    else if(health == 0){
        cout << "Skull Kid: I can't believe how weak I was... You must have cheated..." << endl;
    }
    
}

void SkullKid::lvlUp(){
   
    level ++;
    exp -= expNextLvl;
    expNextLvl *= 2;

    // update stats
    health = maxHealth;
    maxHealth += 10;
    atk += 4;
    def += 4;
    maxMana += 4;

    cout << "*********************************************************************************" << endl;
    cout << "The Moon smiles upon Skull Kid..." << endl;
    cout << "Skull Kid levelled up!" << endl;
    cout << "*********************************************************************************" << endl;
    printStats();


}
