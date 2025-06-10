#pragma once
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"

namespace Dat{
    struct gameData
    {
        StateMachine stateMachine;
        sf::RenderWindow window;
        AssetManager assetManager;
        InputManager inputManager;
    };
    typedef std::shared_ptr<gameData> GameDataRef;

    class Game
    {
    public:
        Game(int width, int height, const std::string& title);

    private:
        const float dt = 1.0f / 60.0f;
        sf::Clock _clock;
        GameDataRef _data = std::make_shared<gameData>();
        void Run();
    };
}
