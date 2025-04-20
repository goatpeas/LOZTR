#include "Link.h"

int Link::HeroOfLegend(){
    srand((unsigned) time(NULL));
    // damage = attack + rand(9, 11)
    int adda = 9 + rand() % (11 - 9 + 1);
    int damage = atk + adda;
    
    return damage;
}

void Link::ZeldasTears() {
    int addDef = 2 + rand() % (4 - 2 + 1);
    def += addDef;
    cout << "Link used Zelda's Tears! Defense increased by " << addDef << "." << endl;
}

void Link::attack(Character& target) {
    int randChoice = rand() % 2;
    int damage = 0;
    
    if(randChoice == 0){
        damage = 12 + rand() % (15 - 12 + 1);
        cout << "Link attacked! Dealt " << damage << " damage!" << endl;
        gainExp(damage);
    }
    else if(randChoice == 1){
        damage = HeroOfLegend();
        cout << "Link used Hero Of Legend! Dealt " << damage << " damage!" << endl;
        gainExp(damage);
    }
    
    if(target.isDefending()){
        damage = std::max(1, damage - target.getDef() / 2);
        cout << target.getName() << " resisted! Took " << damage << " damage!" << endl;
        target.takeDamage(damage);
        target.stopDefending();
        target.resetDefense();
        gainExp(damage);
    }
    else{
        damage = std::max(0, damage);
        target.takeDamage(damage);
        gainExp(damage);
    }
    
}

void Link::resetDefense() {
    def = baseDef;
}

void Link::defend() {
    defending = true;
    cout << name << " is defending!" << endl;
}

void Link::stopDefending(){
    defending = false;
    cout << name << " stopped defending." << endl;
}

bool Link::isDefending(){
    return defending;
}


void Link::useHeal(){
    if(heals > 0){
        int addHealth = 10 + rand() % (18 - 10 + 1);
        cout << "Link played the Song of Healing. Restored " << addHealth << " health." << endl;
        health += addHealth;
        if(health > maxHealth){
            health = maxHealth;
        }
        heals --;
        cout << heals << " uses remaining." << endl;
    }
    else if(heals <= 0){
        cout << "No uses left!" << endl;
    }
}

void Link::lvlUp(){
   
    level ++;
    exp -= expNextLvl;
    expNextLvl *= 2;

    // update stats
    health = maxHealth;
    maxHealth += 17;
    atk += 3;
    def += 4;
    maxMana += 4;

    cout << "*********************************************************************************" << endl;
    cout << "Link was blessed by the Triforce of Courage!" << endl;
    cout << "Link grew stronger...!!" << endl;
    cout << "*********************************************************************************" << endl;
    printStats();
}
