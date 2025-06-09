#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>

namespace Dat
{
    class Pipe
    {
    public:
        Pipe(GameDataRef data);
        void SpawnTopPipe();
        void SpawnBottomPipe();
        void SpawnInvisiblePipe();
        void SpawnScorePipe();
        void movePipes(float dt);
        void DrawPipes();
        void randomPipes();
        std::vector<sf::Sprite> &getSprites();
        std::vector<sf::Sprite> &getScorePipes();
    private:
        GameDataRef _data;
        std::vector<sf::Sprite> pipes;
        std::vector<sf::Sprite> scorePipes;
        int landHeight;
        int pipe_y;
    };
}
