#include <iostream>
#include <string>
#include "Character.h"
#include "Wizard.h"

Wizard::Wizard(const string name, double health, double attackStrength, int rank) : Character(WIZARD, name, health, attackStrength), rank(rank) {}
void Wizard::attack(Character &charName) {
    double dmg = 0.0;
    if(charName.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(charName);
        dmg = this->attackStrength * (static_cast<double>(this->rank)/static_cast<double>(opp.rank));
        cout << "Wizard " << name << " attacks " << charName.getName() << " --- POOF!!" << endl;
        cout << charName.getName() << " takes " << dmg << " damage." << endl;
        charName.setHealth(charName.getHealth() - dmg);
        return;
    }
    
    dmg = this->attackStrength;
    charName.damage(dmg);
    cout << "Wizard " << this->name << " attacks " << charName.getName() << " --- POOF!!" << endl;
    cout << charName.getName() << " takes " << dmg << " damage." << endl;

}
