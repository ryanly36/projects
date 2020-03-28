#include <iostream>
#include "Character.h"

using namespace std;

Character::Character(HeroType type, const string &name, double health, double attackStrength) : type(type), name(name), health(health), attackStrength(attackStrength) {}

HeroType Character::getType() const {
    return this->type;
}
const string & Character::getName() const {
    return this->name;
}
int Character::getHealth() const {
    return this->health;
}
void Character::setHealth(double h) {
    this->health = h;
}
void Character::damage(double d) {
    setHealth(health-d);
}
bool Character::isAlive() const {
    if(this->getHealth() > 0) {
        return true;
    }
    return false;

       }
