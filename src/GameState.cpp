#pragma once

#include <sstream>
#include "DEFINITIONS.h"
#include "GameState.h"
#include "Land.h"
#include "GameOverState.h"
#include <iostream>

namespace Dat
{
    GameState::GameState(GameDataRef data) : _data(data)
    {

    }

    void GameState::Init()
    {
        _data->assetManager.loadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
        _data->assetManager.loadTexture("Pipe Up", PIPE_UP_FILEPATH);
        _data->assetManager.loadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
        _data->assetManager.loadTexture("Scoring Pipe", SCORING_PIPE_FILEPATH);
        _data->assetManager.loadTexture("Land", LAND_FILEPATH);
        _data->assetManager.loadTexture("Bird", BIRD_FILEPATH);
        _data->assetManager.loadFont("Flappy Font", FLAPPY_FONT_FILEPATH);
        pipe = new Pipe(_data);
        land = new Land(_data);
        bird = new Bird(_data);
        displayHUD = new DisplayHUD(_data);

        _background.setTexture(_data->assetManager.getTexture("Game Background"));

        _score = 0;
        displayHUD->updateScore(_score);

        _gameState = GameStates::eReady;
    }

    void GameState::HandleInput()
    {
        sf::Event event;

        while (_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                _data->window.close();
            }
            if (_data->inputManager.IsClicked(_background, sf::Mouse::Left, _data->window))
            {
                if (GameStates::eGameOver != _gameState)
                {
                    _gameState = GameStates::ePlaying;
                    bird->tap();
                }
            }
        }
    }

    void GameState::Update(float dt)
    {
        if (GameStates::eGameOver != _gameState)
        {
            land->moveLand(dt);
        }
        if (GameStates::ePlaying == _gameState)
        {
            pipe->movePipes(dt);
            if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
            {
            pipe->randomPipes();
            pipe->SpawnTopPipe();
            pipe->SpawnBottomPipe();
            pipe->SpawnScorePipe();
            clock.restart();
            }
            bird->update(dt);
            std::vector<sf::Sprite> landSprites = land->getSprites();
            for (int i = 0; i < landSprites.size(); i++)
            {
                if (collision.CheckCollision(bird->getSprite(), landSprites.at(i)))
                {
                    _gameState = GameStates::eGameOver;
                    clock.restart();
                }
            }

            std::vector<sf::Sprite> pipeSprites = pipe->getSprites();
            for (int i = 0; i < pipeSprites.size(); i++)
            {
                if (collision.CheckCollision(bird->getSprite(), pipeSprites.at(i)))
                {
                    _gameState = GameStates::eGameOver;
                    clock.restart();
                }
            }
            if (GameStates::ePlaying == _gameState)
            {
                std::vector<sf::Sprite> &scoringPipes = pipe->getScorePipes();
                for (int i = 0; i < scoringPipes.size(); i++)
                {
                if (collision.CheckCollision(bird->getSprite(), scoringPipes.at(i)))
                {
                    _score++;
                    displayHUD->updateScore(_score);
                    std::cout << "Score: " << _score << std::endl;
                    scoringPipes.erase(scoringPipes.begin() + i);
                }
             }
            }
        }
        if (GameStates::eGameOver == _gameState)
        {
            if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER)
            {
                _data->stateMachine.AddState(StateRef(new GameOverState(_data, _score)), true);
            }
        }
    }

    void GameState::Draw(float dt)
    {
        _data->window.clear(sf::Color::Red);

        _data->window.draw(this->_background);
        pipe->DrawPipes();
        land->drawLand();
        bird->draw();
        displayHUD->draw();
        _data->window.display();
    }
}