#ifndef BASECHARACTER_H
#define BASECHARACTER_H

#include <string>

class BaseCharacter {
protected:
    double x_;
    double y_;
    int hp_;
public:
    BaseCharacter(double pos_x = 0.0, double pos_y = 0.0, int hp = 100);
    virtual ~BaseCharacter();

    void move(double delta_x, double delta_y);
    bool is_alive() const;
    void get_damage(int amount); // уменьшает hp
    double get_x() const;
    double get_y() const;
    int get_hp() const;
};

#endif // BASECHARACTER_H
