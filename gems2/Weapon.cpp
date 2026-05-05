#include "Weapon.h"
#include "BaseCharacter.h"
#include "Exceptions.h"
#include <cmath>
#include <iostream>

Weapon::Weapon() : name_("Fists"), damage_(1), range_(1.0) {}
Weapon::Weapon(const std::string& name, int damage, double range)
    : name_(name), damage_(damage), range_(range) {}

std::string Weapon::get_name() const { return name_; }
int Weapon::get_damage() const { return damage_; }
double Weapon::get_range() const { return range_; }

void Weapon::hit(BaseCharacter& actor, BaseCharacter& target) const {
    if (!target.is_alive()) {
        throw DeadTargetException("The enemy has already been defeated.");
    }
    double dx = actor.get_x() - target.get_x();
    double dy = actor.get_y() - target.get_y();
    double dist = std::sqrt(dx*dx + dy*dy);
    if (dist > range_) {
        throw OutOfRangeException("The enemy is too far for weapons "" + name_ + "".");
    }
    target.get_damage(damage_);
    std::cout << "Weapon "" << name_ << "" caused " << damage_
              << " damage. (Distance: " << dist << ")\n";
                  if (!target.is_alive()) {
        std::cout << "The enemy was defeated!\n";
    }
}
std::ostream& operator<<(std::ostream& os, const Weapon& w) {
    os << w.name_ << " (damage=" << w.damage_ << ", range=" << w.range_ << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Weapon& w) {
    // простой ввод: имя без пробелов, затем урон, затем дальность
    is >> w.name_ >> w.damage_ >> w.range_;
    return is;
}
