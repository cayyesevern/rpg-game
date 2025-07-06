#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>



sf::Vector2f NormalizeVector(sf::Vector2f vector) {
	sf::Vector2f normalizedVector;
	float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);

	return sf::Vector2f(vector.x / magnitude, vector.y / magnitude);
}


int main()
{
	//-------------------------------- INITIALIZE --------------------------------

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);

	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 1.5f;
	sf::Vector2f bulletDirection;

	//player
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	 
	if (playerTexture.loadFromFile("C:/Users/kesav/source/repos/rpg-game/RPG-Game/Assets/Player/Textures/spritesheet.png")) {
		std::cout << "Player image loaded" << std::endl;
		playerSprite.setTexture(playerTexture);
	
		int XIndex = 0;
		int YIndex = 0;

		playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
		playerSprite.scale(sf::Vector2f(3, 3));
	}
	else {
		std::cout << "Player image failed to load" << std::endl;
	}

	//skeleton 
	sf::Texture skeletonTexture;
	sf::Sprite skeletonSprite;

	
	if (skeletonTexture.loadFromFile("C:/Users/kesav/source/repos/rpg-game/RPG-Game/Assets/Skeleton/Textures/spritesheet.png")) {
		std::cout << "Skeleton image loaded" << std::endl;
		skeletonSprite.setTexture(skeletonTexture);
		skeletonSprite.setPosition(sf::Vector2f(400,100));

		int XIndex = 0;
		int YIndex = 2;

		skeletonSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
		skeletonSprite.scale(sf::Vector2f(3, 3));
	}
	else {
		std::cout << "Skeleton image failed to load" << std::endl;
	}


	//-------------------------------- INITIALIZE --------------------------------

	//main game loop
	while (window.isOpen())
	{
		//-------------------------------- UPDATE --------------------------------
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Vector2f position = playerSprite.getPosition();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D))
			playerSprite.setPosition(position + sf::Vector2f(1,0));
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A))
			playerSprite.setPosition(position + sf::Vector2f(-1, 0));
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)) 
			playerSprite.setPosition(position + sf::Vector2f(0, -1));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S))
			playerSprite.setPosition(position + sf::Vector2f(0, 1));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));	
			bullets[bullets.size() - 1].setPosition(playerSprite.getPosition());
		}

		for (size_t i = 0; i < bullets.size(); i++) {
			sf::Vector2f bulletDirection = skeletonSprite.getPosition() - bullets[i].getPosition();
			bulletDirection = NormalizeVector(bulletDirection);
			bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
		}
		
		//-------------------------------- UPDATE --------------------------------

		//-------------------------------- DRAW --------------------------------
		window.clear(sf::Color::Black);
		window.draw(playerSprite);
		window.draw(skeletonSprite);
		for (size_t i = 0; i < bullets.size(); i++) {
			window.draw(bullets[i]);
		}
		window.display();
		//-------------------------------- DRAW --------------------------------
	}

	return 0;
}