#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace Dat
{
    class GameOverState : public State
    {
    public:
        GameOverState(GameDataRef data, int score);

        void Init();

        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;

        sf::Sprite _background;
        sf::Sprite _gameOverTitle;
        sf::Sprite _gameOverBody;
        sf::Sprite _againBtn;

        sf::Text _scoreText;
        sf::Text _highScoreText;

        int score;
        int highScore;
    };
}

