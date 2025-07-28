#pragma once

#include <SFML/Graphics.hpp>

class Skeleton
{
private:
	sf::Texture texture;
	sf::Text healthText; 
	sf::Font font; 

public:
	int health;
	sf::Sprite sprite;
	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;
public:
	Skeleton();
	~Skeleton();

	void ChangeHealth(int hp);
	void Load();
	void Initialize();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
};

