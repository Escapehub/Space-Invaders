#include "../header/bullet.h"

Bullet::Bullet() {

}

void Bullet::createBullet(sf::Vector2f spawnPos) {
  playerpos = spawnPos;

  this->setPosition(spawnPos.x + 20, spawnPos.y -40);
}

bool Bullet::Shoot(sf::RenderWindow& window, sf::Texture& bulletTexture) {
    this->move(0, -0.1);
    this->setTexture(bulletTexture);
    window.draw(*this);
    if (this->getPosition().y <= 0)
      return true;

    return false;
}
