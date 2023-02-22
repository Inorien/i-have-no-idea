//its for dev ok
#pragma once

#include "item.h"

namespace Item::Weapon {

//todo refactor sword : weapon : item
class Sword : public Item {
public:
  Sword() :
    Item("Sword")
  {}
};

}
