#ifndef BULLET_H
#define BULLET_H
#include "entity.h"

class Bullet : public Entity
{
public:
  Bullet();
  bool Shoot(sf::RenderWindow&, sf::Texture& bulletTexture);
  void createBullet(sf::Vector2f);
private:
  sf::Vector2f playerpos;
  sf::Clock clock;
};

#endif // !BULLET_H
