#include "../header/bullet.h"

Bullet::Bullet() {

}

void Bullet::createBullet(sf::Vector2f spawnPos) {
  playerpos = spawnPos;
  bulletTexture.loadFromFile("sprites/bullet.png");
  this->setTexture(bulletTexture);
  this->setPosition(spawnPos.x + 20, spawnPos.y -40);
}

void Bullet::Shoot(sf::RenderWindow& window) {
  while (this->getPosition().y > 0) {
    this->move(0, -0.01);
  }
}
