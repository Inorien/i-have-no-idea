#include <iostream>

#include "mob/player.h"

int main() {

  std::string name;
  std::cin >> name;

  Mob::Player player(name);

  name = player.getInfo().getName();
  std::cout << "Created a player with name: " << name << "\n";
  std::cout << player.getStats();

  return 0;

}
