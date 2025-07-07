#include "Player.h"
#include "Math.h"
#include <iostream>


void Player::Load() {
	if (texture.loadFromFile("C:/Users/kesav/source/repos/rpg-game/RPG-Game/Assets/Player/Textures/spritesheet.png")) {
		std::cout << "Player image loaded" << std::endl;
		sprite.setTexture(texture);

		int XIndex = 0;
		int YIndex = 0;

		sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
		sprite.scale(sf::Vector2f(3, 3));
	}
	else {
		std::cout << "Player image failed to load" << std::endl;
	}
}

void Player::Update(Skeleton& skeleton) {

	sf::Vector2f position = sprite.getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D))
		sprite.setPosition(position + sf::Vector2f(1, 0));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A))
		sprite.setPosition(position + sf::Vector2f(-1, 0));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W))
		sprite.setPosition(position + sf::Vector2f(0, -1));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S))
		sprite.setPosition(position + sf::Vector2f(0, 1));

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));
		bullets[bullets.size() - 1].setPosition(sprite.getPosition());
	}

	for (size_t i = 0; i < bullets.size(); i++) {
		sf::Vector2f bulletDirection = skeleton.sprite.getPosition() - bullets[i].getPosition();
		bulletDirection = Math::NormalizeVector(bulletDirection);
		bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
	}

}

void Player::Initialize() {
}

void Player::Draw(sf::RenderWindow& window) {
	window.draw(sprite);
	for (size_t i = 0; i < bullets.size(); i++) {
		window.draw(bullets[i]);
	}
}