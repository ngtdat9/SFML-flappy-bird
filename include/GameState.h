#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Pipe.h"
#include "Land.h"
#include "Bird.h"
#include "Collision.h"
#include "displayHUD.h"

namespace Dat
{
    class GameState : public State
    {
    public:
        GameState(GameDataRef data);

        void Init();

        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;

        sf::Sprite _background;
        Pipe *pipe;
        Land *land;
        Bird *bird;
        DisplayHUD *displayHUD;
        Collision collision;
        sf::Clock clock;
        int _gameState;
        int _score;
    };
}
