#include "header/entity.h"
#include "header/bullet.h"

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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      player.Move(Entity::Direction::Right);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      player.Move(Entity::Direction::Left);

    // Making bullet fly up the screen
    for (int i = 0; i < bullets.size(); i++) {
      if(bullets[i].Shoot(window, bulletTexture))
        bullets.erase(bullets.begin() + i);
    }
    window.draw(player);
    window.display();
  }

  return EXIT_SUCCESS;
}
