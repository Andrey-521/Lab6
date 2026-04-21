#include "BaseCharacter.h"
#include <algorithm>

BaseCharacter::BaseCharacter(double x, double y, int hp_): pos_x(x), pos_y(y), hp(hp_) {}

BaseCharacter::~BaseCharacter() {}

void BaseCharacter::move(double delta_x, double delta_y) {
    pos_x += delta_x;
    pos_y += delta_y;
}

bool BaseCharacter::is_alive() const {
    return hp > 0;
}

void BaseCharacter::get_damage(int amount) {
    hp -= amount;
    if (hp < 0) hp = 0;
}

double BaseCharacter::get_x() const { return pos_x; }
double BaseCharacter::get_y() const { return pos_y; }
int BaseCharacter::get_hp() const { return hp; }
