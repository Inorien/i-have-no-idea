//Vital statistics
#pragma once

#include <map>
#include <stdexcept>

#include <iostream>

namespace Mob {

//this already looks like a trash system
enum class StatName {
  HITPOINTS
};

static std::string statName2String(const StatName& statName) {
  switch(statName) {
    case (StatName::HITPOINTS):
      return "HITPOINTS";
    default:
      throw std::runtime_error("Query for unknown statName made: " + (int)statName);
  }
}

class Stat {
public:

  void setValue(const unsigned value) {
    m_value = value;
  }

  const auto& getValue() const {return m_value;}

private:
  unsigned m_value{0};
};

class Stats {

  std::map<StatName, Stat> m_stats;

  auto& getStat(const StatName& statName) {
    const auto stat {m_stats.find(statName)};
    if (stat != m_stats.end()) {
      return stat->second;
    }
    throw std::runtime_error("Attempt made to get unset stat " + statName2String(statName));
  }

  //cba working out how to make this tidy
  const auto& getStat(const StatName& statName) const {
    const auto stat {m_stats.find(statName)};
    if (stat != m_stats.end()) {
      return stat->second;
    }
    throw std::runtime_error("Attempt made to get unset stat " + statName2String(statName));
  }

public:

  friend std::ostream& operator<<(std::ostream& os, const Stats& stats);

  Stats(const Stats&) = delete;
  Stats& operator=(const Stats&) = delete;
  Stats(Stats&&) = delete;
  Stats& operator=(Stats&&) = delete;
  ~Stats() = default;

  Stats() {
    //gross
    m_stats.emplace(std::make_pair<StatName, Stat>(StatName::HITPOINTS, Stat()));
  }

  const auto& getStatValue(const StatName& statName) const {
    return getStat(statName).getValue();
  }

  void setStatValue(const StatName& statName, const unsigned value) {
    auto& stat {getStat(statName)};
    stat.setValue(value);
  }

};

std::ostream& operator<<(std::ostream& os, const Stats& stats) {
  os << "Stats:\n";
  for (const auto& stat : stats.m_stats) {
    os << statName2String(stat.first) << " : "
      << stat.second.getValue() << ", ";
  }
  os << std::endl;
  return os;
}

}
