#include "header/entity.h"
#include "header/bullet.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(1920, 1080), "Space Invaders");
  sf::Texture playerTexture;
  playerTexture.loadFromFile("sprites/player.png");

  Entity player(playerTexture, sf::IntRect(0, 0, 70, 50));
  player.setPosition(window.getSize().x / 2, window.getSize().y -50);
  player.setSpeed(0.1f);

  std::vector<Bullet> bullets;

  while(window.isOpen()) {
    window.clear();
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        window.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      player.Move(Entity::Direction::Right);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      player.Move(Entity::Direction::Left);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
      Bullet bullet;
      bullet.createBullet(player.getPosition());
      bullets.push_back(bullet);
    }

    for (int i = 0; i < bullets.size(); i++) {
      window.draw(bullets[i]);
      bullets[i].Shoot(window);
    }
    window.draw(player);
    window.display();
  }

  return EXIT_SUCCESS;
}
