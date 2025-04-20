#ifndef SK_H
#define SK_H

#include "Character.h"

class SkullKid : public Character{
    
public:
    SkullKid() : Character(){
        name = "Skull Kid";
        level = 1;
        health = 100;
        maxHealth = 100;
        atk = 13;
        def = 12;
        baseDef = def;
        mana = 18;
        maxMana = mana;
        exp = 0;
        expNextLvl = 100;
        defending = false;
    }
    
    void TimesUp(Character&);
    void majorasMask();
   
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
    
};
#endif


