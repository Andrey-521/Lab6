#ifndef BASEENEMY_H
#define BASEENEMY_H

#include "BaseCharacter.h"
#include "Weapon.h"
#include <string>
#include <iostream>

class BaseEnemy : public BaseCharacter {
private:
    Weapon weapon_;
public:
    BaseEnemy(double pos_x, double pos_y, int hp, const Weapon& weapon);
    virtual ~BaseEnemy();

    void hit(BaseCharacter& target); // бьёт цель собственным оружием

    friend std::ostream& operator<<(std::ostream& os, const BaseEnemy& e);
};

#endif // BASEENEMY_H

