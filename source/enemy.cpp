#include "../header/enemy.h"

Enemy::Enemy() {

}
void Enemy::createEnemies(sf::Texture texture, sf::RenderWindow& window) {
  sf::IntRect enemy1(0, 0, 60, 60);
  sf::IntRect enemy2(0, 60, 60, 60);
  sf::IntRect enemy3(0, 120, 60, 60);

  // create first row
  for (int i = 0; i < 13; i++) {
    sf::Sprite sprite(texture, enemy1);
    sprite.setPosition(window.getSize().x / 3, i * 60);
    enemies[i][0] = sprite;
  }
}

void Enemy::drawEnemies(sf::RenderWindow& window) {
  for (int i = 0; i < 13; i++) {
    window.draw(enemies[i][0]);
  }
}
