#include <iostream>
#include <string>
#include "Character.h"
#ifndef WIZARD_H
#define WIZARD_H

class Wizard : public Character {
    private:
        int rank;
    
    public:
        Wizard(const string name, double health, double attackStrength, int rank);
        void attack(Character &charName);
};
#endif
