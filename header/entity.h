#ifndef ENTITY_H
#define ENTITY_H
#include "animation.h"
#include <iostream>

class Entity : public Animation
{
public:
  Entity();
  Entity(sf::Texture&, sf::IntRect);
  void setSpeed(float);
  enum Direction { Up, Down, Left, Right };
  void Move(Direction);
private:
  Direction currentDirection;
  float speed;
};

#endif // !ENTITY_H
