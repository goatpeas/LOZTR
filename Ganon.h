#ifndef GANON_H
#define GANON_H

#include "Character.h"

class Ganon : public Character{
    
public:
    Ganon() : Character(){
        name = "Ganon";
        level = 1;
        health = 100;
        maxHealth = 100;
        atk = 17;
        def = 14;
        baseDef = def;
        mana = 10;
        maxMana = mana;
        exp = 0;
        expNextLvl = 100;
        defending = false;
    }
    
    void warlockPunch(Character&); // damage = attack + rand(7, 10) Void demonShield(); // def += rand(1, 4)
    // Note : don’t want to change actual base stat, def and attack should remain the same unless they are leveled up. Also, the random value that it arrives on is the amount that is subtracted from mana, which is regained once they do a regular attack.
    void demonShield();
   
    int getUserChoice(); // presents the user with two choices for special moves, Warlock Punch or Demon Shield. returns value of choice.
    void spMove(Character&) override; // using the value of getUserChoice, utilizes either the Warlock Punch function or the Demon Shield function.
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
    
    //getters
    
    
};
#endif

