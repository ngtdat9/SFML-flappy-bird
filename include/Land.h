#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>
namespace Dat
{
    class Land
    {
    public:
        Land(GameDataRef data);
        void moveLand(float dt);
        void drawLand();
        std::vector<sf::Sprite> &getSprites();
    private:
        GameDataRef _data;
        std::vector<sf::Sprite> _landSprites;
    };
}