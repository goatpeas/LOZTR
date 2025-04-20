#ifndef VAATI_H
#define VAATI_H

#include "Character.h"

class Vaati : public Character{
    
public:
    Vaati() : Character(){
        name = "Vaati";
        level = 1;
        health = 100;
        maxHealth = 100;
        atk = 16;
        def = 11;
        baseDef = def;
        mana = 20;
        maxMana = mana;
        exp = 0;
        expNextLvl = 100;
        defending = false;
    }
    
    void divineLightning(Character&);
    void amethystShield();
   
    int getUserChoice();
    void spMove(Character&) override;
    void attack(Character&) override;
    void printStats() override;
    
    // defending
    void defend() override;
    bool isDefending() override;
    void stopDefending() override;
    void resetDefense() override;
    void useHeal() override;
    
    void printDialogue() override;
    void lvlUp() override; 

    
};
#endif

