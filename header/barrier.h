#ifndef BARRIER_H
#define BARRIER_H
#include "entity.h"

class Barrier : public Entity
{
public:
  Barrier(sf::Texture&, int);
  virtual ~Barrier();
  void Restore();
  void Hit();
private:
  std::vector<sf::IntRect> textureRects = {sf::IntRect(0,0, 100, 75), sf::IntRect(100, 0, 100, 75), sf::IntRect(200,0, 100, 75), sf::IntRect(300,0, 100, 75), sf::IntRect(400,0, 100, 75)};
  int status;
  void Update();
};

#endif // !BARRIER_H
