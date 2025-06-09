#pragma once
#include <SFML/Graphics.hpp>
namespace Dat
{
    class Collision
    {
        public:
        Collision();
        bool CheckCollision(sf::Sprite sprite1,sf::Sprite sprite2);
    };
}
