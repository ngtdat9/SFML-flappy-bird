
#include "SplashState.h"
#include <sstream>
#include<DEFINITIONS.h>
#include <iostream>

#include "MainMenuState.h"

namespace Dat
{
    SplashState::SplashState(GameDataRef data) : _data(data)
    {

    }
    void SplashState::Init()
    {
        _data->assetManager.loadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
        _background.setTexture(this->_data->assetManager.getTexture("Splash State Background"));
        _background.setPosition(0, 0);
    }
    void SplashState::HandleInput()
    {
        sf::Event event;
        while (_data->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                this->_data->window.close();
            }
        }
    }
    void SplashState::Update(float dt)
    {
        if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
        {
            this->_data->stateMachine.AddState(StateRef(new MainMenuState(_data)), true);
        }
    }
    void SplashState::Draw(float dt)
    {
        this->_data->window.clear();
        this->_data->window.draw(this->_background);
        this->_data->window.display();
    }
}
