#include "BaseCharacter.h"
#include <algorithm>

BaseCharacter::BaseCharacter(double pos_x, double pos_y, int hp)
    : x_(pos_x), y_(pos_y), hp_(hp) {}

BaseCharacter::~BaseCharacter() {}

void BaseCharacter::move(double delta_x, double delta_y) {
    x_ += delta_x;
    y_ += delta_y;
}

bool BaseCharacter::is_alive() const {
    return hp_ > 0;
}

void BaseCharacter::get_damage(int amount) {
    if (amount < 0) return;
    hp_ -= amount;
    if (hp_ < 0) hp_ = 0;
}

double BaseCharacter::get_x() const { return x_; }
double BaseCharacter::get_y() const { return y_; }
int BaseCharacter::get_hp() const { return hp_; }

