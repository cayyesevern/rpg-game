#pragma once
#include "Skeleton.h"
#include <SFML/Graphics.hpp>

class Player
{

private:
	sf::Texture texture;

	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 1.5f;
	sf::Vector2f bulletDirection;

public:
	sf::Sprite sprite;
public:
	void Load();
	void Initialize();
	void Update(Skeleton& skeleton);
	void Draw(sf::RenderWindow& window);
};

