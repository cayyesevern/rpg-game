#pragma once
#include <SFML/Graphics.hpp>

class FrameRate
{
private:
	sf::Text frameRateText; //Sprite
	sf::Font font; //Textures 

	float timer;

public:
	FrameRate();
	~FrameRate();

	void Load();
	void Initialize();
	void Update(double deltaTime);
	void Draw(sf::RenderWindow& window);
};

