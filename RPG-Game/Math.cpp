#include "Math.h"

sf::Vector2f Math::NormalizeVector(sf::Vector2f vector) {
	sf::Vector2f normalizedVector;
	float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);

	return sf::Vector2f(vector.x / magnitude, vector.y / magnitude);
}