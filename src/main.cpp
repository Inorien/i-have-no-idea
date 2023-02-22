#include <iostream>

#include "mob/player.h"

int main() {

  std::string name;
  std::cin >> name;

  Mob::Player player(name);

  std::cout << "Created a player with name: " << player.getInfo().getName() << "\n";

  return 0;

}