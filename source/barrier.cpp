#include "../header/barrier.h"

Barrier::Barrier(sf::Texture& texture, int state) {
  this->setTexture(texture);
  status = state;
  this->Update();
}

Barrier::~Barrier() {

}

void Barrier::Restore() {
  status = 0;
  this->Update();
}

void Barrier::Hit() {
  status++;
  this->Update();
}

void Barrier::Update() {
  this->setTextureRect(textureRects[status]);
}
