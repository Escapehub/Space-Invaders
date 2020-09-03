#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"

class Enemy : public Entity
{
public:
  Enemy();
  void drawEnemies(sf::RenderWindow&);
  void createEnemies(sf::Texture, sf::RenderWindow&);
private:
  //std::vector< std::vector<sf::Sprite> > enemies(12, std::vector<sf::Sprite>(6));
  sf::Sprite enemies[12][6];
};
#endif // !ENEMY_H
