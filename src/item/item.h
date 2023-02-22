//Item base class
#pragma once

#include <string>

namespace Item {

class Item {

  std::string m_name;

public:

  virtual ~Item() = default;

  explicit Item(std::string name) :
    m_name(std::move(name))
  {}

  const auto& getName() const {return m_name;}


};
}
