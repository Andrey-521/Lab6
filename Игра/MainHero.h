#ifndef MAINHERO_H
#define MAINHERO_H

#include "BaseCharacter.h"
#include "Weapon.h"
#include <vector>
#include <string>

class MainHero : public BaseCharacter {
private:
    std::string name;
    std::vector<Weapon> inventory;
    int current_weapon;
    const int max_hp = 200;
public:
    MainHero(const std::string& name_, double x, double y, int hp_);
    void hit(BaseCharacter& target);
    void add_weapon(const Weapon& w);
    void next_weapon();
    void heal(int amount);
    const std::string& get_name() const;
};

#endif
