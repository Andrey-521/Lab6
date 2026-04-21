#ifndef BASECHARACTER_H
#define BASECHARACTER_H

class BaseCharacter {
protected:
    double pos_x;
    double pos_y;
    int hp;
public:
    BaseCharacter(double x=0.0, double y=0.0, int hp_=100);
    virtual ~BaseCharacter();

    void move(double delta_x, double delta_y);
    bool is_alive() const;
    void get_damage(int amount);
    double get_x() const;
    double get_y() const;
    int get_hp() const;
};

#endif
