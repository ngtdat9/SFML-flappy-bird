#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "Game.h"

namespace Dat
{
    class Bird
    {
    public:
        Bird(GameDataRef data);
        void draw();
        void update(float dt);
        void tap();
        sf::Sprite &getSprite();
    private:
        GameDataRef _data;
        sf::Sprite birdSprite;
        sf::Clock clock;
        int birdState;
    };
}
