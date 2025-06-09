#pragma once
#include<SFML/Graphics.hpp>
#include<DEFINITIONS.h>
#include"Game.h"

namespace Dat
{
    class DisplayHUD
    {
        public:
        DisplayHUD(GameDataRef data);
        void draw();
        void updateScore(int score);
        private:
        GameDataRef _data;
        sf::Text _scoreText;
    };
}
