#pragma once

#include <sstream>
#include "DEFINITIONS.h"
#include "MainMenuState.h"
#include "GameState.h"

#include <iostream>

namespace Dat
{
    MainMenuState::MainMenuState(GameDataRef data) : _data(data)
    {

    }

    void MainMenuState::Init()
    {
        this->_data->assetManager.loadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
        this->_data->assetManager.loadTexture("Game Title", GAME_TITLE_FILEPATH);
        this->_data->assetManager.loadTexture("Play Button", PLAY_BUTTON_FILEPATH);

        _background.setTexture(this->_data->assetManager.getTexture("Main Menu Background"));
        _title.setTexture(this->_data->assetManager.getTexture("Game Title"));
        _playButton.setTexture(this->_data->assetManager.getTexture("Play Button"));

        _title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), _title.getGlobalBounds().height / 2);
        _playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2));
    }

    void MainMenuState::HandleInput()
    {
        sf::Event event;

        while (this->_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }

            if (this->_data->inputManager.IsClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
            {
                // Switch To Main Menu
                this->_data->stateMachine.AddState(StateRef(new GameState(_data)), true);
                std::cout << "Play Button Clicked" << std::endl;
            }
        }
    }

    void MainMenuState::Update(float dt)
    {

    }

    void MainMenuState::Draw(float dt)
    {
        this->_data->window.clear(sf::Color::Red);

        this->_data->window.draw(this->_background);
        this->_data->window.draw(this->_title);
        this->_data->window.draw(this->_playButton);

        this->_data->window.display();
    }
}