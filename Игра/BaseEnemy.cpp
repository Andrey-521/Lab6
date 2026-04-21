#include "BaseEnemy.h"
#include <iostream>

BaseEnemy::BaseEnemy(double x, double y, int hp_, const Weapon& w)
    : BaseCharacter(x,y,hp_), weapon(w) {}

void BaseEnemy::hit(BaseCharacter& target) {
    weapon.hit(*this, target);
}

std::ostream& operator<<(std::ostream& os, const BaseEnemy& e) {
    os << "The enemy is in position (" << e.get_x() << ", " << e.get_y() << ") with weapons " << e.weapon;
    return os;
}
