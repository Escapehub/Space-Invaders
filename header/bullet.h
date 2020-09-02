#ifndef BULLET_H
#define BULLET_H
#include "entity.h"

class Bullet : public Entity
{
public:
  Bullet();
  void Shoot(sf::RenderWindow&);
  void createBullet(sf::Vector2f);
private:
  sf::Texture bulletTexture;
  sf::Vector2f playerpos;
  sf::Clock clock;
};

#endif // !BULLET_H
