#include "MainHero.h"
#include "Exceptions.h"
#include <iostream>

MainHero::MainHero(const std::string& name, double pos_x, double pos_y, int hp)
    : BaseCharacter(pos_x, pos_y, hp), name_(name), current_weapon_index_(-1) {}

MainHero::~MainHero() {}

void MainHero::hit(BaseCharacter& target) {
    if (current_weapon_index_ < 0 || current_weapon_index_ >= static_cast<int>(inventory_.size())) {
        throw NoWeaponException("I am unarmed!");
    }
    const Weapon& w = inventory_[current_weapon_index_];
    try {
        w.hit(*this, target);
    } catch (const GameException& ex) {
        // пробрасываем дальше или выводим
        throw;
    }
}

void MainHero::add_weapon(const Weapon& weapon) {
    inventory_.push_back(weapon);
    if (current_weapon_index_ == -1) {
        current_weapon_index_ = 0;
        std::cout << "Weapons picked up: " << weapon.get_name() << "\n";
    } else {
        std::cout << "Added to inventory: " << weapon.get_name() << "\n";
    }
}

void MainHero::next_weapon() {
    if (inventory_.empty()) {
        std::cout << "I don't have a weapon.\n";
        current_weapon_index_ = -1;
        return;
    }
    if (current_weapon_index_ == -1) current_weapon_index_ = 0;
    else current_weapon_index_ = (current_weapon_index_ + 1) % static_cast<int>(inventory_.size());
    std::cout << "Changed weapons to: " << inventory_[current_weapon_index_].get_name() << "\n";
}

void MainHero::heal(int amount) {
    if (amount <= 0) return;
    hp_ += amount;
    if (hp_ > 200) hp_ = 200;
    std::cout << "I was healed on " << amount << " HP. Current HP=" << hp_ << "\n";
}
std::string MainHero::get_name() const { return name_; }

void MainHero::print_inventory() const {
    if (inventory_.empty()) {
        std::cout << "Inventory is empty.\n";
        return;
    }
    std::cout << "Inventory:\n";
    for (size_t i = 0; i < inventory_.size(); ++i) {
        std::cout << (i == static_cast<size_t>(current_weapon_index_) ? " * " : "   ")
                  << i << ": " << inventory_[i] << "\n";
    }
}

int MainHero::weapon_count() const { return static_cast<int>(inventory_.size()); }
