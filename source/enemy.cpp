#include "../header/enemy.h"

Enemy::Enemy(sf::Texture& texture) {
  createEnemies(texture);
  this->speed = 0.1f;
}

Enemy::~Enemy() {

}

void Enemy::drawEnemies(sf::RenderWindow& window) {
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 5; j++) {
      enemies[i][j].Move(Entity::Direction::Right);
      //if (enemies[i][j].getPosition().x > (window.getSize().x - 30))
      window.draw(enemies[i][j]);
    }
  }
}

void Enemy::createEnemies(sf::Texture& texture) {
  // Enemy Texture Rects
  sf::IntRect enemy1Rect(0, 0, 60, 60);
  sf::IntRect enemy2Rect(0, 60, 60, 60);
  sf::IntRect enemy3Rect(0, 120, 60, 60);

  sf::IntRect currentRect = enemy3Rect;
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 5; j++) {
      if (j == 1)
        currentRect = enemy2Rect;
      else if (j == 3)
        currentRect = enemy3Rect;

        enemies[i][j].setTexture(texture);
        enemies[i][j].setTextureRect(currentRect);
        enemies[i][j].setPosition(i * 60, j * 60);
    }
  }
}

sf::FloatRect Enemy::getBounds() {
  sf::FloatRect bounds[12][5];
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 5; j++) {
      bounds[i][j] = enemies[i][j].getGlobalBounds();
    }
  }
  return bounds;
}
