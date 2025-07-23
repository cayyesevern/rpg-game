#pragma once
#include "Skeleton.h"
#include <SFML/Graphics.hpp>

class Player
{

private:
	sf::Texture texture;

	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 1.5f;
	float playerSpeed = 2.0f;
	sf::Vector2f bulletDirection;

	sf::RectangleShape boundingRectangle;

	sf::Vector2i size;

public:
	sf::Sprite sprite;
public:
	void Load();
	void Initialize();
	void Update(float deltaTime, Skeleton& skeleton);
	void Draw(sf::RenderWindow& window);
};

