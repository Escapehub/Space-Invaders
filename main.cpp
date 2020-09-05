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
  Enemy enemies;
  sf::Texture enemyTexture;
  enemyTexture.loadFromFile("sprites/enemies.png");

  // Barriers
  sf::Texture barrierTexture;
  barrierTexture.loadFromFile("sprites/shields.png");
  Barrier barrier1;
  barrier1.setStatus(4);

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

    // Making bullet fly up the screen
    for (int i = 0; i < bullets.size(); i++) {
      if(bullets[i].Shoot(window, bulletTexture))
        bullets.erase(bullets.begin() + i);
    }
    window.draw(player);
    barrier1.draw(window, barrierTexture, sf::Vector2f(window.getSize().x / 5, window.getSize().y - window.getSize().y / 4));
    enemies.drawEnemies(window, enemyTexture);
    window.display();
  }

  return EXIT_SUCCESS;
}
