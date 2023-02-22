#include <iostream>

#include "mob/player.h"
#include "item/sword.h"

int main() {

  std::string name;
  std::cin >> name;

  Mob::Player player(name);

  std::cout << "Created a player with name: " << player.getInfo().getName() << "\n";

  std::cout << player.getInventory();

  auto& inv {player.getInventory()};
  inv.add(std::make_unique<Item::Weapon::Sword>());

  std::cout << player.getInventory();

  return 0;

}
