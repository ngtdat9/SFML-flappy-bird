#pragma once
#include <SFML/Graphics.hpp>

namespace Dat
{
    class InputManager
    {
    public:
        bool IsClicked(sf::Sprite obj, sf::Mouse::Button button, sf::RenderWindow& window);
    };
}
