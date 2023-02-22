//Inventory system
#pragma once

#include <src/item/item.h>

#include <iostream>
#include <memory>
#include <vector>

//Doesnt sound like it should be in this namespace
namespace Mob {

class Inventory {
  //todo capacity
  std::vector<std::unique_ptr<Item::Item>> m_inv;
public:

  Inventory() = default; //default -> empty inventory
  Inventory(const Inventory&) = delete;
  Inventory& operator=(const Inventory&) = delete;
  Inventory(Inventory&&) = delete;
  Inventory& operator=(Inventory&&) = delete;
  ~Inventory() = default;

  void add(std::unique_ptr<Item::Item> item) noexcept {
    m_inv.emplace_back(std::move(item));
  }

  friend std::ostream& operator<<(std::ostream& os, const Inventory& inv);

};

std::ostream& operator<<(std::ostream& os, const Inventory& inv) {
  os << "Inventory:\n";
  for (const auto& item : inv.m_inv) {
    os << item->getName() << ", ";
  }
  os << std::endl;
  return os;
}

}
