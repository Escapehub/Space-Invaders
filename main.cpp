#include "header/entity.h"
#include "header/bullet.h"
#include "header/enemy.h"
#include "header/barrier.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(1920, 1080), "Space Invaders");

  // Player assets
  sf::Texture playerTexture;
  playerTexture.loadFromFile("sprites/player.png");
  Entity player(playerTexture, sf::IntRect(0, 0, 70, 50));
  player.setPosition(window.getSize().x / 2, window.getSize().y -50);
  player.setSpeed(0.1f);

  // Bullet assets
  std::vector<Bullet> bullets;
  sf::Texture bulletTexture;
  bulletTexture.loadFromFile("sprites/bullet.png");

  // Enemies
  sf::Texture enemyTexture;
  enemyTexture.loadFromFile("sprites/enemies.png");
  Enemy enemies(enemyTexture);
  sf::Clock enemyClock;

  // Barriers
  sf::Texture barrierTexture;
  barrierTexture.loadFromFile("sprites/shields.png");
  int windowQuater = window.getSize().x / 5;
  Barrier barrier1(barrierTexture, 0);
  barrier1.setPosition(sf::Vector2f(windowQuater, (window.getSize().y / 5) * 4));
  Barrier barrier2(barrierTexture, 0);
  barrier2.setPosition(sf::Vector2f(windowQuater * 2, (window.getSize().y / 5) * 4));
  Barrier barrier3(barrierTexture, 0);
  barrier3.setPosition(sf::Vector2f(windowQuater * 3, (window.getSize().y / 5) * 4));
  Barrier barrier4(barrierTexture, 0);
  barrier4.setPosition(sf::Vector2f(windowQuater * 4, (window.getSize().y / 5) * 4));
  std::vector<Barrier> barriers = { barrier1, barrier2, barrier3, barrier4 };

  //auto enemyBounds = enemies.getBounds();
  while(window.isOpen()) {
    window.clear();
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        window.close();

      // Player shoot event
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space) {
          Bullet bullet;
          bullet.createBullet(player.getPosition());
          bullets.push_back(bullet);
        }
      }
    }

    // Player movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)|| sf::Keyboard::isKeyPressed(sf::Keyboard::D))
      player.Move(Entity::Direction::Right);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
      player.Move(Entity::Direction::Left);

    // Loop player around the screen
    if (player.getPosition().x > window.getSize().x)
      player.setPosition(0, player.getPosition().y);
    else if (player.getPosition().x < 0)
      player.setPosition(window.getSize().x, player.getPosition().y);

    // Hit reg for bullet to barrier
    if(!bullets.empty()) {
      for (int i = 0; i < bullets.size(); i++) {
        if (bullets[i].getGlobalBounds().intersects(barriers[0].getGlobalBounds())) {
          barriers[0].Hit();
          bullets.erase(bullets.begin()+i);
        }
        if (bullets[i].getGlobalBounds().intersects(barriers[1].getGlobalBounds())) {
          barriers[1].Hit();
          bullets.erase(bullets.begin()+i);
        }
        if (bullets[i].getGlobalBounds().intersects(barriers[2].getGlobalBounds())) {
          barriers[2].Hit();
          bullets.erase(bullets.begin()+i);
        }
        if (bullets[i].getGlobalBounds().intersects(barriers[3].getGlobalBounds())) {
          barriers[3].Hit();
          bullets.erase(bullets.begin()+i);
        }
        //auto enemyBounds = enemies.getBounds();
      }
    }

    // Making bullet fly up the screen
    for (int i = 0; i < bullets.size(); i++) {
      if(bullets[i].Shoot(window, bulletTexture))
        bullets.erase(bullets.begin() + i);
    }
    window.draw(player);
    for (Barrier bazza : barriers) {
      window.draw(bazza);
    }
    enemies.moveEnemiesRight(window);
    enemies.drawEnemies(window);
    window.display();
  }

  return EXIT_SUCCESS;
}
