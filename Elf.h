#include <iostream>
#include "Character.h"
#ifndef ELF_H
#define ELF_H

class Elf : public Character {
    private:
    string famName;
    
    public:
    
    Elf(const string name, double health, double attackStrength, const string famName);
    
    void attack(Character &charName);
};
#endif