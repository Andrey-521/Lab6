#include <iostream>
#include <vector>
#include <limits>
#include "MainHero.h"
#include "BaseEnemy.h"
#include "Weapon.h"
#include "Exceptions.h"
#include <algorithm>
   

void clear_input() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::cout << "Enter the hero's name: ";
    std::string hero_name;
    std::cin >> hero_name;

    MainHero hero(hero_name, 0.0, 0.0, 200);

    // создадим несколько врагов
    std::vector<BaseEnemy> enemies;
    enemies.emplace_back(5.0, 0.0, 50, Weapon("ShortSword", 15, 2.0));
    enemies.emplace_back(8.0, 1.0, 60, Weapon("Bow", 10, 6.0));
    enemies.emplace_back(3.0, -2.0, 40, Weapon("Axe", 20, 1.5));

    bool running = true;
    while (running) {
        std::cout << "\n=== Menu ===\n";
        std::cout << "1. Show hero status\n";
        std::cout << "2. Show enemies\n";
        std::cout << "3. Move (delta x, delta y)\n";
        std::cout << "4. Pick up a weapon\n";
        std::cout << "5. Change weapon\n";
        std::cout << "6. Attack enemy (by index)\n";
        std::cout << "7.Heal\n";
        std::cout << "8. Enable enemy turn (they attack the hero if they are alive)\n";
        std::cout << "0. Exit\n";
        std::cout << "Select an option: ";
        int opt;
        if (!(std::cin >> opt)) {
            clear_input();
            continue;
        }
        switch (opt) {
            case 1: {
                std::cout << "Hero " << hero.get_name()
                          << " in position (" << hero.get_x() << ", " << hero.get_y() << "), HP=" << hero.get_hp() << "\n";
                hero.print_inventory();
                break;
            }
            case 2: {
                for (size_t i = 0; i < enemies.size(); ++i) {
                    std::cout << i << ": " << enemies[i] << "\n";
                }
                break;
            }
            case 3: {
                double dx, dy;
                std::cout << "Enter delta_x delta_y: ";
                if (!(std::cin >> dx >> dy)) { clear_input(); break; }
                hero.move(dx, dy);
                std::cout << "The hero moved to (" << hero.get_x() << ", " << hero.get_y() << ")\n";
                break;
            }
            case 4: {
                std::cout << "Enter weapon (name damage range), for example: Bow 12 5.0\n";
                Weapon w;
                if (!(std::cin >> w)) { clear_input(); break; }
                hero.add_weapon(w);
                break;
            }
            case 5: {
                hero.next_weapon();
                break;
            }
            case 6: {
                std::cout << "Enter enemy index to attack: ";
                int idx;
                if (!(std::cin >> idx)) { clear_input(); break; }
                if (idx < 0 || static_cast<size_t>(idx) >= enemies.size()) {
                    std::cout << "Invalid index.\n";
                    break;
                }
                try {
                    hero.hit(enemies[idx]);
                } catch (const NoWeaponException& ex) {
                    std::cout << ex.what() << "\n";
                } catch (const OutOfRangeException& ex) {
                    std::cout << "Error: " << ex.what() << "\n";
                } catch (const DeadTargetException& ex) {
                    std::cout << "Error: " << ex.what() << "\n";
                } catch (const GameException& ex) {
                    std::cout << "Error: " << ex.what() << "\n";
                                    }
                break;
            }
            case 7: {
                int amount;
                std::cout << "How much HP to restore? ";
                if (!(std::cin >> amount)) { clear_input(); break; }
                hero.heal(amount);
                break;
            }
            case 8: {
                std::cout << "Enemy move:\n";
                for (size_t i = 0; i < enemies.size(); ++i) {
                    if (enemies[i].is_alive()) {
                        enemies[i].hit(hero);
                        if (!hero.is_alive()) {
                            std::cout << "The hero fell in battle...\n";
                            running = false;
                            break;
                        }
                    }
                }
                break;
            }
            case 0:
                running = false;
                break;
            default:
                std::cout << "Invalid option.\n";
        }

        // Удалим поверженных врагов из списка (не обязательно, но удобно)
        enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
                    [](const BaseEnemy& e){ return !e.is_alive(); }), enemies.end());

        if (enemies.empty()) {
            std::cout << "All enemies are defeated! Victory!\n";
            running = false;
        }
    }

    std::cout << "Game over.\n";
    return 0;
}
