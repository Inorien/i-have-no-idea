#include <iostream>

#include "mob/player.h"
#include "item/sword.h"

int main() {

  std::string name;
  std::cin >> name;

  Mob::Player player(name);

  name = player.getInfo().getName();
  std::cout << "Created a player with name: " << name << "\n";
  std::cout << player.getStats();

  std::cout << player.getInventory();

  auto& inv {player.getInventory()};
  inv.add(std::make_unique<Item::Weapon::Sword>());

  std::cout << player.getInventory();

  return 0;

}
