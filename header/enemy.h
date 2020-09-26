#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"

class Enemy : public Entity
{
public:
  Enemy(sf::Texture&);
  virtual ~Enemy();
  void drawEnemies(sf::RenderWindow&);
private:
  void createEnemies(sf::Texture&);
  sf::Sprite enemies[12][5];
};
#endif // !ENEMY_H
