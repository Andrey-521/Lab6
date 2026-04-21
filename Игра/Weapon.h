#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

class BaseCharacter;

class Weapon {
private:
    std::string name;
    int damage;
    double range;
public:
    Weapon();
    Weapon(const std::string& name_, int damage_, double range_);

    void hit(BaseCharacter& actor, BaseCharacter& target) const;

    const std::string& get_name() const;
    int get_damage() const;
    double get_range() const;

    friend std::ostream& operator<<(std::ostream& os, const Weapon& w);
    friend std::istream& operator>>(std::istream& is, Weapon& w);
};

#endif
