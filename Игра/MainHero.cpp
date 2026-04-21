#include "MainHero.h"
#include <iostream>

MainHero::MainHero(const std::string& name_, double x, double y, int hp_)
    : BaseCharacter(x,y,hp_), name(name_), current_weapon(-1) {}

void MainHero::hit(BaseCharacter& target) {
    if (current_weapon == -1) {
        std::cout << "I am unarmed\n";
        return;
    }
    Weapon& w = inventory[current_weapon];
    w.hit(*this, target);
}

void MainHero::add_weapon(const Weapon& w) {
    inventory.push_back(w);
    if (current_weapon == -1) {
        current_weapon = 0;
        std::cout << "Picked it up " << inventory[current_weapon] << "\n";
    } else {
        std::cout << "Picked it up " << w.get_name() << "\n";
    }
}

void MainHero::next_weapon() {
    if (inventory.empty()) {
        std::cout << "I am unarmed\n";
        return;
    }
    if ((int)inventory.size() == 1) {
        std::cout << "I only have one weapon.\n";
        return;
    }
    current_weapon = (current_weapon + 1) % static_cast<int>(inventory.size());
    std::cout << "Changed weapons to " << inventory[current_weapon] << "\n";
}

void MainHero::heal(int amount) {
    if (amount <= 0) return;
    hp += amount;
    if (hp > max_hp) hp = max_hp;
    std::cout << "I got treatment and now I'm healthy. " << hp << "\n";
}

const std::string& MainHero::get_name() const { return name; }
