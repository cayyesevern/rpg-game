#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    sf::CircleShape shape(50.0f);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(sf::Vector2f(100, 100));
    shape.setOutlineThickness(10);
    shape.setOutlineColor(sf::Color::Green);

    sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
    rectangle.setFillColor(sf::Color::Red);
    //rectangle.setPosition(sf::Vector2f(100, 100));
    //rectangle.setOutlineThickness(10);
    //rectangle.setOutlineColor(sf::Color::Green);
    //rectangle.setOrigin(sf::Vector2f(60, 25));


    sf::RectangleShape rectangle1(sf::Vector2f(120.f, 50.f));
    rectangle1.setFillColor(sf::Color::Red);
    rectangle1.setPosition(sf::Vector2f(100, 100));
    rectangle1.setOutlineThickness(10);
    rectangle1.setOutlineColor(sf::Color::Green);
    rectangle1.setOrigin(sf::Vector2f(60, 25));
    rectangle1.setRotation(90);


    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(rectangle);
        //window.draw(rectangle1);
        //window.draw(shape);

        // end the current frame
        window.display();
    }

    return 0;
}