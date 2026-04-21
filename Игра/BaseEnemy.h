#ifndef BASEENEMY_H
#define BASEENEMY_H

#include "BaseCharacter.h"
#include "Weapon.h"
#include <iostream>

class BaseEnemy : public BaseCharacter {
private:
    Weapon weapon;
public:
    BaseEnemy(double x, double y, int hp_, const Weapon& w);
    void hit(BaseCharacter& target);
    friend std::ostream& operator<<(std::ostream& os, const BaseEnemy& e);
};

#endif
