#ifndef BARRIER_H
#define BARRIER_H
#include "entity.h"

class Barrier : public Entity
{
public:
  Barrier();
  virtual ~Barrier();
  void draw(sf::RenderWindow&, sf::Texture, sf::Vector2f);
  void setStatus(int);
  int getStatus();
private:
  int status;
};

#endif // !BARRIER_H
