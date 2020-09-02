#include "../header/animation.h"

Animation::Animation() {

}

void Animation::setStartRect(sf::IntRect ani) {
  startRect = ani;
}

void Animation::setAnimationSpeed(float speed) {
  animationSpeed = speed;
}

void Animation::setFrameSize(int size) {
  frameSize = size;
}

void Animation::update() {
  if (clock.getElapsedTime().asSeconds() > animationSpeed) {
    if (startRect.left == frameSize)
      startRect.left = 0;
    else
      startRect.left += frameSize;

      this->setTextureRect(startRect);
      clock.restart();
  }
}
