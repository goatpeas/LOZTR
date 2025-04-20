#ifndef CHAR_H
#define CHAR_H

#include <string>
#include <iostream>

using namespace std; 

class Character{

    public: 

    //constructors
    Character() : name(" "), level(1), health(100), maxHealth(100), exp(0), expNextLvl(0),
              atk(5), def(5), mana(5), baseDef(5), defending(false), heals(3), maxMana(5){}

   
    
    // defending
    virtual void defend() = 0;
    virtual bool isDefending() = 0;
    virtual void stopDefending() = 0;
    virtual void resetDefense() = 0;
    
    // attacking
    virtual void attack(Character&) = 0;
    virtual void spMove(Character&);
    
    virtual ~Character() {}
    
    // healing
    virtual void useHeal() = 0;
    
    virtual void gainExp(int);
    virtual void lvlUp() = 0;
    
    int getDef() { return def; }
    int getAtk() {return atk;}
    int getHealth() { return health;}
    string getName() {return name;}
    int getMaxHealth() {return maxHealth;}
    int getHeals()  {return heals;}
    
    virtual void takeDamage(int);
    virtual void printStats();

    virtual void saveData(string);
    virtual void loadData(string);
    
    virtual void printDialogue(); 

    protected: 
    string name; 
    int level, health, maxHealth, exp, expNextLvl, atk, def, mana, baseDef, heals, maxMana;
    bool defending;


};
#endif
