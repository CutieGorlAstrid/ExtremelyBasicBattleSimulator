#include <iostream>
#include <string>
#include <chrono>
#include <thread>

class Player {
// The player object, where most of the player variables are stored
   public:
      std::string name;
      std::string weaponname;
      int health;
      int attack;

      void Attack() {
      // Attack function - called whenever the player attacks
          std::cout << name << " attacks! Dealt " << attack << " points of damage!" << std::endl;
      }

      void Damage(int damageval) {
      // Damage function - called whenever the player takes damage
          std::cout << name << " received " << damageval << " points of damage! " << name << " now has " << health << " points of health!\n" << std::endl;
          health = health - damageval;
      }
};

class Enemy {
// The enemy object, pretty much a copy of the player object
   public:
      std::string name;
      std::string weaponname;
      int health;
      int attack;

      void Attack() {
      // Attack function - called whenever the player attacks
          std::cout << name << " attacks! Dealt " << attack << " points of damage!" << std::endl;
      }

      void Damage(int damageval) {
      // Damage function - called whenever the player takes damage
          std::cout << name << " received " << damageval << " points of damage! " << name << " now has " << health << " points of health!\n" << std::endl;
          health = health - damageval;
      }
};

int main() {
// This code is executed at runtime
    Player Player1;
    Enemy Enemy1;
    
    Player1.health = 0;
    Player1.attack = 0;

    Enemy1.health = 0;
    Enemy1.attack = 0;

    while (Player1.name == "")
    {
        std::cout << "Please input your name!\n> ";
        std::cin >> Player1.name;
    }
    while (Enemy1.name == "")
    {
        std::cout << "Please input your enemy's name!\n> ";
        std::cin >> Enemy1.name;
    }

    while (Player1.health < 1)
    {
        std::cout << "Please input your desired health!\n> ";
        std::cin >> Player1.health;
    }
    while (Enemy1.health < 1)
    {
        std::cout << "Please input your enemy's health!\n> ";
        std::cin >> Enemy1.health;
    }

    while (Player1.attack < 1)
    {
        std::cout << "Please input your desired attack value!\n> ";
        std::cin >> Player1.attack;
    }
    while (Enemy1.attack < 1)
    {
        std::cout << "Please input your enemy's attack value!\n> ";
        std::cin >> Enemy1.attack;
    }

    std::cout << Player1.name << " challenges " << Enemy1.name << " to a fight!\n" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    while (Enemy1.health > 0 & Player1.health > 0) {
        Player1.Attack();
        Enemy1.Damage(Player1.attack);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        Enemy1.Attack();
        Player1.Damage(Enemy1.attack);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    if (Enemy1.health < 1) {
        std::cout << Enemy1.name << " has been defeated! Victory!" << std::endl;
    }
    if (Player1.health < 1) {
        std::cout << Player1.name << " has been defeated! Failure!" << std::endl;
    }
}