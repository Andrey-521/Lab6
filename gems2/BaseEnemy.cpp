#include "BaseEnemy.h"
#include "Exceptions.h"
#include <iostream>

BaseEnemy::BaseEnemy(double pos_x, double pos_y, int hp, const Weapon& weapon)
    : BaseCharacter(pos_x, pos_y, hp), weapon_(weapon) {}

BaseEnemy::~BaseEnemy() {}

void BaseEnemy::hit(BaseCharacter& target) {
    try {
        weapon_.hit(*this, target);
    } catch (const GameException& ex) {
        std::cout << "The enemy was unable to attack: " << ex.what() << "\n";
    }
}

std::ostream& operator<<(std::ostream& os, const BaseEnemy& e) {
    os << "The enemy is in position (" << e.get_x() << ", " << e.get_y() << "), HP=" << e.get_hp()
       << ", with weapons: " << e.weapon_;
    return os;
}
