//Player class
#pragma once

#include "info.h"
#include "inventory.h"
#include "stats.h"
#include "mob.h"

namespace Mob {

class Player : public Mob {

  Info m_info{}; //name etc
  Inventory m_inventory; //duh
  Stats m_stats{}; //hp, weight, str, agi, int etc
  //Spellbook m_spellbook; //attacks and abilities

public:

  explicit Player(std::string name) :
    Mob(0) 
  {
    m_info.setName(std::move(name));
  }

  Player() = delete;
  Player(const Player&) = delete;
  Player& operator=(const Player&) = delete;
  Player(Player&&) = delete; //?
  Player& operator=(Player&&) = delete; //??
  ~Player() = default; //???

  const auto& getInfo() const {return m_info;}
  //write access is bad
  auto& getInventory() {return m_inventory;}
  
  const auto& getInventory() const {return m_inventory;}

  const auto& getStats() const {return m_stats;}

};

}
