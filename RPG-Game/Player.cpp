#include "Player.h"
#include "Math.h"
#include <iostream>

void Player::Initialize() {
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Blue);
	boundingRectangle.setOutlineThickness(1);

	size = sf::Vector2i(64, 64);
	
}

Player::Player() : playerSpeed(2.0f), maxfireRate(150), fireRateTimer(0)
{
}

Player::~Player()
{
}

void Player::Load() {
	if (texture.loadFromFile("C:/Users/kesav/source/repos/rpg-game/RPG-Game/Assets/Player/Textures/spritesheet.png")) {
		std::cout << "Player image loaded" << std::endl;
		sprite.setTexture(texture);

		int XIndex = 0;
		int YIndex = 0;

		sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
		sprite.setPosition(sf::Vector2f(0,0));

		sprite.scale(sf::Vector2f(3, 3));
		boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
		
	}
	else {
		std::cout << "Player image failed to load" << std::endl;
	}
}

void Player::Update(float deltaTime, Skeleton& skeleton, sf::Vector2f& mousePosition) {

	sf::Vector2f position = sprite.getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D))
		sprite.setPosition(position + sf::Vector2f(1, 0) * playerSpeed * deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A))
		sprite.setPosition(position + sf::Vector2f(-1, 0) * playerSpeed * deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W))
		sprite.setPosition(position + sf::Vector2f(0, -1) * playerSpeed * deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S))
		sprite.setPosition(position + sf::Vector2f(0, 1) * playerSpeed * deltaTime);

	fireRateTimer += deltaTime;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxfireRate) {
		bullets.push_back(Bullet());
		bullets[bullets.size() - 1].Initialize(sprite.getPosition(), mousePosition, 1.5f);
		fireRateTimer = 0;
	}

	for (size_t i = 0; i < bullets.size(); i++) {

		bullets[i].Update(deltaTime);
		if (Math::DidRectCollide(bullets[i].GetGlobalBounds(), skeleton.sprite.getGlobalBounds())) {
			skeleton.ChangeHealth(-10);
			bullets.erase(bullets.begin() + i);
			std::cout << "Skeleton Health: " << skeleton.health <<  std::endl;
		}
	}

	boundingRectangle.setPosition(sprite.getPosition());

	/*if (sprite.getGlobalBounds().intersects(skeleton.sprite.getGlobalBounds())) {
		std::cout << "Collision" << std::endl;
	}*/
}

void Player::Draw(sf::RenderWindow& window) {
	window.draw(sprite);
	window.draw(boundingRectangle);
	for (size_t i = 0; i < bullets.size(); i++) {
		bullets[i].Draw(window);
	}
}