#include "../header/enemy.h"

Enemy::Enemy() {

}

Enemy::~Enemy() {

}

void Enemy::drawEnemies(sf::RenderWindow& window, sf::Texture texture) {
  createEnemies(texture);
  for (sf::Sprite sprite : row1) {
    window.draw(sprite);
  }
  for (sf::Sprite sprite : row2) {
    window.draw(sprite);
  }
  for (sf::Sprite sprite : row3) {
    window.draw(sprite);
  }
  for (sf::Sprite sprite : row4) {
    window.draw(sprite);
  }
  for (sf::Sprite sprite : row5) {
    window.draw(sprite);
  }
}

void Enemy::moveEnemies(sf::RenderWindow& window) {
  
}

void Enemy::createEnemies(sf::Texture& texture) {
  // Enemy Texture Rects
  sf::IntRect enemy1Rect(0, 0, 60, 60);
  sf::IntRect enemy2Rect(0, 60, 60, 60);
  sf::IntRect enemy3Rect(0, 120, 60, 60);

  for (int i = 0; i < 12; i++) {
    // Row 1
    row1[i].setTexture(texture);
    row1[i].setTextureRect(enemy1Rect);
    row1[i].setPosition(i * 60, 0);
    // Row 2
    row2[i].setTexture(texture);
    row2[i].setTextureRect(enemy2Rect);
    row2[i].setPosition(i * 60, 60);
    // Row 3
    row3[i].setTexture(texture);
    row3[i].setTextureRect(enemy2Rect);
    row3[i].setPosition(i * 60, 120);
    // Row 4
    row4[i].setTexture(texture);
    row4[i].setTextureRect(enemy3Rect);
    row4[i].setPosition(i * 60, 180);
    // Row 5
    row5[i].setTexture(texture);
    row5[i].setTextureRect(enemy3Rect);
    row5[i].setPosition(i * 60, 240);
  }
}
