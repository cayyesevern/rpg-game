#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Skeleton.h"
#include "FrameRate.h"

int main()
{
	//INITIALIZE
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);
	//window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	Player player;
	Skeleton skeleton;
	FrameRate framerate;

	framerate.Initialize();
	player.Initialize();
	skeleton.Initialize();

	//LOAD
	framerate.Load();
	player.Load();
	skeleton.Load();

	sf::Clock clock;

	while (window.isOpen())
	{

		//UPDATE
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//calculate time
		float deltaTime = clock.restart().asMicroseconds() / 1000.f;

		sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
		std::cout << "Mouse position: " << mousePosition.x << " " << mousePosition.y << std::endl;

		framerate.Update(deltaTime);
		skeleton.Update(deltaTime);
		player.Update(deltaTime, skeleton, mousePosition); 
		
		//DRAW
		window.clear(sf::Color::Black);
		player.Draw(window);
		skeleton.Draw(window);
		framerate.Draw(window);
		window.display();
	}
	return 0;
}