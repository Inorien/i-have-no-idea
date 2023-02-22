//Base mob type

//TODO mob factory

namespace Mob {

class Mob {
public:
  
  explicit Mob(const int ID) : 
    m_ID(ID) 
  {}

  Mob() = delete; //IDs must be kept unique, assign from factory (owner)
  Mob(const Mob&) = delete;
  Mob& operator=(const Mob&) = delete;
  Mob(Mob&&) = default;
  Mob& operator=(Mob&&) = default;
  ~Mob() = default;

  const auto getID() const {return m_ID;}



private:
  int m_ID{};
};

}