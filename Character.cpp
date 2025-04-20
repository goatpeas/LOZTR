#include "Character.h"
#include <algorithm>
#include <fstream>

void Character::takeDamage(int damage){
    health -= damage;
}

void Character::useHeal(){
    
    if(heals > 0){
        int addHealth = 10 + rand() % (15 - 10 + 1);
        cout << name << " restored " << addHealth << " health!" << endl;
        health += addHealth;
        if(health > maxHealth){
            health = maxHealth;
        }
        heals --;
        cout << heals << " heals left." << endl;
    }
    else if(heals <= 0){
        cout << "No heals left!" << endl;
    }
    
}

void Character::gainExp(int damage){
    
    // need to have condiions for gaining exp???
    // 1. you gain exp from hitting link? too much exp though...
    // 2. gain exp from getting link down 1/4 health --> not enough lvling up..?
    // ^^ dont rlly need to worry abt that too much rn.
    
    exp += damage;
    
    if(exp >= expNextLvl){
        lvlUp();
    }

}

void Character::printStats(){

    cout << "Character: " << name << endl;
    cout << "Level: " << level << endl; 
    cout << "Health: " << health << "/" << maxHealth << endl; 
    cout << "Attack: " << atk << endl;
    cout << "Defense: " << def << endl;
    cout << "Mana: " << mana << endl; 
    cout << "EXP: " << exp << "/" << expNextLvl << endl; 

}

void Character::lvlUp(){
   
    // increase level, subtract total exp from the expNextLvl
    level ++;
    exp -= expNextLvl;
    expNextLvl *= 2;

    // update stats
    health = maxHealth;
    maxHealth += 10;
    atk += 1;
    def += 2;
    maxMana += 2;

    // note: stats could change by different increment depending on character
    // like vaati is a mage, so mana goes up a lot, but def doesnt
    // ganon is pure phys, so def and a go up, but mana doesnt
    // skull kid is both, so def, a, and mana go up, but only by a little

    // link's stats all increase by a generous amount each time you level up. lol. sorry!
    
    cout << "*******************************************************" << endl;
    cout << name << " leveled up!" << endl;
    printStats(); 
    cout << "*******************************************************" << endl;

}

void Character::attack(Character& target){ // can i make it take in a target name
    
    int damage = atk;
    
    if(target.defending){
        damage = std::max(0, damage - target.getDef());
        target.takeDamage(damage);
        cout << target.getName() << "resisted damage! Remaining health: " << target.health << endl;
        target.stopDefending();
    }
    else{
        target.takeDamage(damage);
    }
    
    exp += damage;
    mana += damage;
    
}
    
// defending
void Character::resetDefense() {
    def = baseDef;
}

void Character::defend() {
    isDefending();
    resetDefense();
    cout << name << " is defending!" << endl;
    
}

void Character::stopDefending(){
    defending = false;
    cout << name << " stopped defending." << endl;
}

bool Character::isDefending(){
    return defending;
}

void Character::saveData(string filename){
    ofstream fout;
    fout.open(filename);
    
    if(fout.is_open()){
        fout << name << endl;
        fout <<  level << endl;
        fout <<  health << endl;
        fout << atk << endl;
        fout <<  def << endl;
        fout << mana << endl;
        fout << exp << endl;
        cout << "Character data saved to " << filename << endl;
    }
    else{
        cout << "ERROR: File did not open." << endl;
    }

}

void Character::loadData(string filename){
    
    ifstream fin;
    fin.open(filename);
    
    
    if(fin.is_open()){
        fin >> name;
        fin >> level;
        fin >> health;
        fin >> atk;
        fin >> def;
        fin >> mana;
        fin >> exp;
        cout << "Character data loaded from " << filename << endl;
    }
    else{
        cout << "ERROR: File did not load." << endl;
    }
    
    
}

void Character::spMove(Character&){
    
    
    
}

void Character::printDialogue(){
    
    
}
