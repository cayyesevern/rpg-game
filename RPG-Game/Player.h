#pragma once
#include "Skeleton.h"
#include "Bullet.h"
#include <SFML/Graphics.hpp>

class Player
{

private:
	sf::Texture texture;

	std::vector<Bullet> bullets;
	float playerSpeed;
	float maxfireRate;
	float fireRateTimer;
	sf::Vector2f bulletDirection;

	sf::RectangleShape boundingRectangle;

	sf::Vector2i size;

public:
	sf::Sprite sprite;
public:
	Player();
	~Player();

	void Load();
	void Initialize();
	void Update(float deltaTime, Skeleton& skeleton, sf::Vector2f &mousePosition);
	void Draw(sf::RenderWindow& window);
};

