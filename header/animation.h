#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>

class Animation: public sf::Sprite
{
public:
	Animation();
	void setStartRect(sf::IntRect);
	void setAnimationSpeed(float);
	void setFrameSize(int);
private:
	sf::Clock clock;
	float animationSpeed;
	int frameSize;
	sf::IntRect startRect;
protected:
	void update();
};

#endif // !ANIMATION.H
