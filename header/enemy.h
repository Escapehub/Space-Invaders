#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"

class Enemy : public Entity
{
public:
  Enemy();
  virtual ~Enemy();
  void drawEnemies(sf::RenderWindow&, sf::Texture);
  void moveEnemies(sf::RenderWindow&);
private:
  //std::vector< std::vector<sf::Sprite> > enemies(12, std::vector<sf::Sprite>(6));
  void createEnemies(sf::Texture&);
  sf::Sprite row1[12];
  sf::Sprite row2[12];
  sf::Sprite row3[12];
  sf::Sprite row4[12];
  sf::Sprite row5[12];
};
#endif // !ENEMY_H
