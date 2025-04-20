#ifndef LINK_H
#define LINK_H

#include "Character.h"

class Link : public Character{
    
public:
    Link() : Character() {
        name = "Link";
        maxHealth = 100;
        level = 1;
        atk = 15;
        def = 14;
        exp = 0;
        expNextLvl = 100;
        baseDef = def;
    }
    
    int HeroOfLegend(); // damage = attack + rand(9, 11)
    void ZeldasTears(); // def += rand(3, 6) until Link uses the Defend move. Triforce ascii art will appear
    int oppDecision(); // Link randomly selects between two choices to either Defend or attack, and subsequently uses that move from the two functions above.
    void attack(Character&) override;
    
    void defend() override;
    bool isDefending() override;
    void stopDefending() override;
    void resetDefense() override;
    
    void useHeal() override;
    void lvlUp() override;

 

    
};
#endif

