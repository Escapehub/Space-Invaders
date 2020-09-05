#include "../header/entity.h"

Entity::Entity() {

}

Entity::Entity(sf::Texture& texture, sf::IntRect startrect) {
  this->setTexture(texture);
  this->setTextureRect(startrect);
}

Entity::~Entity() {
  
}

void Entity::setSpeed(float f) {
  speed = f;
}

void Entity::Move(Direction direction) {
  switch (direction) {
    case Up:
      this->move(0, -speed);
      break;
    case Down:
      this->move(0, speed);
      break;
    case Left:
      this->move(-speed, 0);
      break;
    case Right:
      this->move(speed, 0);
      break;
  }
}
