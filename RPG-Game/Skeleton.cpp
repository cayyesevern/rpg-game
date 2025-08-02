#include "Skeleton.h"
#include <iostream>


Skeleton::Skeleton() : health(400)
{
}

Skeleton::~Skeleton()
{
}

void Skeleton::ChangeHealth(int hp)
{
	health += hp;
	healthText.setString(std::to_string(health));
}

void Skeleton::Load() {
	if (font.loadFromFile("Assets/Fonts/arial.ttf")) {
		std::cout << "Font loaded! " << std::endl;
		healthText.setFont(font);
	}
	else {
		std::cout << "Failed to load font!" << std::endl;
	}

	if (texture.loadFromFile("C:/Users/kesav/source/repos/rpg-game/RPG-Game/Assets/Skeleton/Textures/spritesheet.png")) {
		std::cout << "Skeleton image loaded" << std::endl;
		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(0,0));

		int XIndex = 0;
		int YIndex = 2;

		sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
		sprite.setPosition(sf::Vector2f(900, 400));
		sprite.scale(sf::Vector2f(3, 3));
		boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
		healthText.setPosition(sprite.getPosition());
		healthText.setString(std::to_string(health));
	}
	else {
		std::cout << "Skeleton image failed to load" << std::endl;
	}
}

void Skeleton::Update(double deltaTime) {
	if (health > 0) {
		boundingRectangle.setPosition(sprite.getPosition());
		healthText.setPosition(sprite.getPosition());
	}
}

void Skeleton::Initialize() {

	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Red);
	boundingRectangle.setOutlineThickness(1);

	size = sf::Vector2i(64, 64);
}

void Skeleton::Draw(sf::RenderWindow& window) {
	if (health > 0) {
		window.draw(sprite);
		window.draw(boundingRectangle);
		window.draw(healthText);
	}
}