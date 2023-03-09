//Vital statistics
#pragma once

#include <map>
#include <stdexcept>

#include <iostream>

namespace Mob {

class Stat {
public:

  explicit Stat(std::string name) : 
    m_name(name)
  {}

  void setValue(const unsigned value) {
    m_value = value;
  }

  const auto& getValue() const {return m_value;}

private:
  unsigned m_value{0};
  std::string m_name;
};

class Stats {

  std::map<std::string, Stat> m_stats;

  auto& getStat(const std::string& statName) {
    const auto stat {m_stats.find(statName)};
    if (stat != m_stats.end()) {
      return stat->second;
    }
    throw std::runtime_error("Attempt made to get unset stat " + statName);
  }

  const auto& getStat(const std::string& statName) const {
    const auto stat {m_stats.find(statName)};
    if (stat != m_stats.end()) {
      return stat->second;
    }
    throw std::runtime_error("Attempt made to get unset stat " + statName);
  }

public:

  friend std::ostream& operator<<(std::ostream& os, const Stats& stats);

  Stats(const Stats&) = delete;
  Stats& operator=(const Stats&) = delete;
  Stats(Stats&&) = delete;
  Stats& operator=(Stats&&) = delete;
  ~Stats() = default;

  Stats() {
    //i hate the string
    m_stats.insert({"Hitpoints", Stat{"Hitpoints"}});
  }

  const auto& getStatValue(const std::string& statName) const {
    return getStat(statName).getValue();
  }

  void setStatValue(const std::string& statName, const unsigned value) {
    auto& stat {getStat(statName)};
    stat.setValue(value);
  }

};

std::ostream& operator<<(std::ostream& os, const Stats& stats) {
  os << "Stats:\n";
  for (const auto& stat : stats.m_stats) {
    os << stat.first << " : "
      << stat.second.getValue() << ", ";
  }
  os << std::endl;
  return os;
}

}
