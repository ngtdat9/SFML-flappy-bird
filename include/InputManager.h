#pragma once
#include <SFML/Graphics.hpp>

namespace Dat
{
    class InputManager
    {
    public:
        InputManager();
        ~InputManager();
        bool IsClicked(sf::Sprite obj, sf::Mouse::Button button, sf::RenderWindow& window);
        sf::Vector2i GetMousePosition(sf::RenderWindow& window);
    };
}
