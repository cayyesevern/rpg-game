#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
private:
	float speed;
	sf::Vector2f direction;
	sf::RectangleShape rectangleShape;

public:
	Bullet();
	~Bullet();

	void Initialize(const sf::Vector2f &position, const sf::Vector2f &target, double speed);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	inline const sf::FloatRect& GetGlobalBounds() { return rectangleShape.getGlobalBounds(); }
};

