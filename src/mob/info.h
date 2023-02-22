//Information about a given mob

#include <string>

namespace Mob {

class Info {
public:

  void setName(std::string name) { 
    m_name = std::move(name) ;
  };
  
  const auto& getName() const {return m_name;}

private:
  std::string m_name;


};

}