#include "Weapon.h"
#include "BaseCharacter.h"
#include "Exceptions.h"
#include <cmath>
#include <iostream>

Weapon::Weapon(): name("fist"), damage(1), range(1.0) {}
Weapon::Weapon(const std::string& name_, int damage_, double range_)
    : name(name_), damage(damage_), range(range_) {
    if (damage_ < 0) throw WeaponException("Damage cannot be negative");
    if (range_ < 0) throw WeaponException("Range cannot be negative");
}

const std::string& Weapon::get_name() const { return name; }
int Weapon::get_damage() const { return damage; }
double Weapon::get_range() const { return range; }

void Weapon::hit(BaseCharacter& actor, BaseCharacter& target) const {
    if (!target.is_alive()) {
        std::cout << "The enemy has already been defeated\n";
        return;
    }
    double dx = actor.get_x() - target.get_x();
    double dy = actor.get_y() - target.get_y();
    double dist = std::sqrt(dx*dx + dy*dy);
    if (dist > range) {
		        std::cout << "The enemy is too far for weapons " << name << "\n";
        return;
    }
    target.get_damage(damage);
    std::cout << "The enemy was damaged by a weapon. " << name << " in size " << damage << "\n";
}

std::ostream& operator<<(std::ostream& os, const Weapon& w) {
    os << w.name;
    return os;
}

std::istream& operator>>(std::istream& is, Weapon& w) {
    is >> w.name >> w.damage >> w.range;
    return is;
}
