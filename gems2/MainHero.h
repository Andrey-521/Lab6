#ifndef MAINHERO_H
#define MAINHERO_H

#include "BaseCharacter.h"
#include "Weapon.h"
#include <vector>
#include <string>

class MainHero : public BaseCharacter {
private:
    std::string name_;
    std::vector<Weapon> inventory_;
    int current_weapon_index_; // -1 если безоружен
public:
    MainHero(const std::string& name, double pos_x = 0.0, double pos_y = 0.0, int hp = 200);
    ~MainHero();

    void hit(BaseCharacter& target); // бьет выбранным оружием
    void add_weapon(const Weapon& weapon); // добавить оружие в инвентарь и экипировать если нужно
    void next_weapon(); // сменить оружие по кругу
    void heal(int amount); // восстановить hp
    std::string get_name() const;
    void print_inventory() const;
    int weapon_count() const;
};

#endif // MAINHERO_H
