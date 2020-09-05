#include "../header/barrier.h"

Barrier::Barrier() {

}

Barrier::~Barrier() {

}

void Barrier::draw(sf::RenderWindow& window, sf::Texture texture, sf::Vector2f pos) {
  this->setTexture(texture);
  this->setPosition(pos);
  window.draw(*this);
}

void Barrier::setStatus(int state) {
  status = state;
  switch (status) {
    case 0:
    case 1:
      this->setTextureRect(sf::IntRect(0,0, 100, 75));
      break;
    case 2:
      this->setTextureRect(sf::IntRect(100, 0, 100, 75));
      break;
    case 3:
      this->setTextureRect(sf::IntRect(200,0, 100, 75));
      break;
    case 4:
      this->setTextureRect(sf::IntRect(300,0, 100, 75));
      break;
    case 5:
      this->setTextureRect(sf::IntRect(400,0, 100, 75));
      break;
  }
}

int Barrier::getStatus() {
  return status;
}
