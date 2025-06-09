#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace Dat
{
    class SplashState : public State
    {
    public:
        SplashState(GameDataRef data);
        void Init() override;
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);
    private:
        GameDataRef _data;
        sf::Sprite _background;
        sf::Clock _clock;
        float _time;
    };
}
