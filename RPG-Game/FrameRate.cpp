#include "FrameRate.h"
#include <iostream>

FrameRate::FrameRate():timer(0) {
}

FrameRate::~FrameRate()
{
}

void FrameRate::Initialize() {
}

void FrameRate::Load() {
	if (font.loadFromFile("Assets/Fonts/arial.ttf")) {
		std::cout << "Font loaded! " << std::endl;
		frameRateText.setFont(font);
	}
	else {
		std::cout << "Failed to load font!" << std::endl;
	}
}

void FrameRate::Update(float deltaTime) {
	timer += deltaTime;

	if (timer >= 100.0) {
		std::string frameRateString = "FPS: " + std::to_string((int)(1000.0 / deltaTime)) + "   frameTime: " + std::to_string(deltaTime);
		frameRateText.setString(frameRateString);
		timer = 0;
	}
	
}

void FrameRate::Draw(sf::RenderWindow& window) {
	window.draw(frameRateText);
}