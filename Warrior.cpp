#include <iostream>
#include <string>
#include "Warrior.h"
#include "Character.h"

Warrior::Warrior(const string name, double health, double attackStrength, const string allegiance) : Character(WARRIOR, name, health, attackStrength), allegiance(allegiance) {}

void Warrior::attack(Character &charName) {
    if(charName.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(charName);
        if(opp.allegiance == this->allegiance) {
            cout << "Warrior " << name << " does not attack Warrior " << charName.getName() << "." << endl;
            cout << "They share an allegiance with " << this->allegiance << "." << endl;
            return;
        }
    }
    double dmg = 0;
    dmg = (this->health/MAX_HEALTH)*this->attackStrength;
//     charName.setHealth(charName.getHealth()-dmg);
    charName.damage(dmg);
    
    cout << "Warrior " << this->name << " attacks " << charName.getName() << " --- SLASH!!" << endl;
    cout << charName.getName() << " takes " << dmg << " damage." << endl;
}
    
