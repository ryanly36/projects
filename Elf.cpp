#include <string>
#include <iostream>
#include "Character.h"
#include "Elf.h"

Elf::Elf(const string name, double health, double attackStrength, const string famName): Character(ELF, name, health, attackStrength), famName(famName) {}

void Elf::attack(Character &charName) {
    double dmg = 0.0;
    if(charName.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(charName);
        if(opp.famName == this->famName) {
            cout << "Elf " << name << " does not attack Elf " << charName.getName() << "." << endl;
            cout << "They are both members of the " << this->famName << " family." << endl;
            return;
        }
    }
        
    dmg = (health/MAX_HEALTH)*attackStrength;
//     charName.setHealth(charName.getHealth() - dmg);
    charName.damage(dmg);
    
    
    
    cout << "Elf " << name << " shoots an arrow at " << charName.getName() << " --- TWANG!!" << endl;
    cout << charName.getName() << " takes "<< dmg << " damage." << endl;
}

    
