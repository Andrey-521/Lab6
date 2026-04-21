#include <iostream>
#include "MainHero.h"
#include "BaseEnemy.h"
#include "Weapon.h"
#include "Exceptions.h"

int main() {
    try {
        MainHero hero("Ivan", 0.0, 0.0, 120);

        Weapon sword("Sword", 30, 2.0);
        Weapon bow("Bow", 15, 10.0);
        Weapon dagger("Dagger", 10, 1.5);

        BaseEnemy e1(1.0, 1.0, 50, dagger);
        BaseEnemy e2(5.0, 0.0, 40, bow);
        BaseEnemy e3(12.0, 0.0, 60, sword);

        std::cout << e1 << "\n";
        std::cout << e2 << "\n";
        std::cout << e3 << "\n";

        hero.add_weapon(bow);
        hero.add_weapon(sword);
        hero.add_weapon(dagger);
        hero.hit(e1);
        hero.hit(e1);
        hero.hit(e1);

        hero.next_weapon();
        hero.hit(e2);
        hero.next_weapon();
        hero.hit(e2);

        hero.move(4.5, 0.0);
        std::cout << "The hero moved to (4.5,0)\n";
        hero.hit(e2);

        hero.move(7.5, 0.0);
        hero.next_weapon();
        hero.hit(e3);

        hero.heal(50);

        hero.hit(e1);

    } catch (const GameException& ex) {
        std::cerr << "Game error: " << ex.what() << "\n";
    } catch (const std::exception& ex) {
        std::cerr << "Std error: " << ex.what() << "\n";
    }

    return 0;
}
