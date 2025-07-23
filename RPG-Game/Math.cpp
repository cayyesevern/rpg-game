#include "Math.h"

sf::Vector2f Math::NormalizeVector(sf::Vector2f vector) {
	sf::Vector2f normalizedVector;
	float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);

	return sf::Vector2f(vector.x / magnitude, vector.y / magnitude);
}

bool Math::DidRectCollide(sf::FloatRect rect1, sf::FloatRect rect2)
{
	if (rect1.left + rect1.width > rect2.left &&
		rect2.left + rect1.width > rect1.left &&
		rect2.top + rect2.height > rect1.top &&
		rect1.top + rect1.height > rect2.top)
		return true;

	return false;
}
