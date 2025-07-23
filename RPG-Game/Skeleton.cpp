#include "Skeleton.h"
#include <iostream>


void Skeleton::Load() {
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
	}
	else {
		std::cout << "Skeleton image failed to load" << std::endl;
	}
}

void Skeleton::Update(float deltaTime) {
	boundingRectangle.setPosition(sprite.getPosition());
}

void Skeleton::Initialize() {

	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Red);
	boundingRectangle.setOutlineThickness(1);

	size = sf::Vector2i(64, 64);
}

void Skeleton::Draw(sf::RenderWindow& window) {
	window.draw(sprite);
	window.draw(boundingRectangle);
}