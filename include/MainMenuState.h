#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace Dat
{
    class MainMenuState : public State
    {
    public:
        MainMenuState(GameDataRef data);
        void Init() override;
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);
    private:
        GameDataRef _data;
        sf::Sprite _background;
        sf::Sprite _title;
        sf::Sprite _playButton;
        float _time;
    };
}
