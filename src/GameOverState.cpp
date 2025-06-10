#pragma once

#include "GameOverState.h"

#include <sstream>
#include "DEFINITIONS.h"
#include "GameState.h"
#include<fstream>
#include <iostream>

namespace Dat
{
    GameOverState::GameOverState(GameDataRef data, int score) : _data(data), score(score)
    {
    }

    void GameOverState::Init()
    {
        std::ifstream readFile;
        readFile.open("../Highscore.txt");
        if (readFile.is_open())
        {
            while (!readFile.eof())
            {
                readFile >> highScore;
            }
        }
        readFile.close();
        std::ofstream writeFile("../Highscore.txt");
        if (writeFile.is_open())
        {
            if (score > highScore)
            {
                highScore = score;
            }
            writeFile << highScore;
        }
        writeFile.close();


        _data->assetManager.loadTexture("Game Over Background", GAME_BACKGROUND_FILEPATH);
        _data->assetManager.loadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);
        _data->assetManager.loadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);

        _background.setTexture(_data->assetManager.getTexture("Game Over Background"));
        _gameOverTitle.setTexture(_data->assetManager.getTexture("Game Over Title"));
        _gameOverBody.setTexture(_data->assetManager.getTexture("Game Over Body"));
        _againBtn.setTexture(_data->assetManager.getTexture("Play Button"));

        _gameOverBody.setPosition(_data->window.getSize().x/2 - _gameOverBody.getGlobalBounds().width/2, _data->window.getSize().y/2 - _gameOverBody.getGlobalBounds().height/2);
        _gameOverTitle.setPosition((_data->window.getSize().x / 2) - (_gameOverTitle.getGlobalBounds().width / 2), _gameOverBody.getPosition().y - (_gameOverTitle.getGlobalBounds().height * 1.2));
        _againBtn.setPosition((_data->window.getSize().x / 2) - (_againBtn.getGlobalBounds().width / 2), _gameOverBody.getPosition().y + _gameOverBody.getGlobalBounds().height + (_againBtn.getGlobalBounds().height * 0.2));

        _scoreText.setFont(_data->assetManager.getFont("Flappy Font"));
        _scoreText.setString(std::to_string(score));
        _scoreText.setCharacterSize(50);
        _scoreText.setFillColor(sf::Color::White);
        _scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);
        _scoreText.setPosition(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 2.15);

        _highScoreText.setFont(this->_data->assetManager.getFont("Flappy Font"));
        _highScoreText.setString(std::to_string(highScore));
        _highScoreText.setCharacterSize(50);
        _highScoreText.setFillColor(sf::Color::White);
        _highScoreText.setOrigin(_highScoreText.getGlobalBounds().width / 2, _highScoreText.getGlobalBounds().height / 2);
        _highScoreText.setPosition(_data->window.getSize().x / 10 * 7, _data->window.getSize().y / 1.78);
    }


    void GameOverState::HandleInput()
    {
        sf::Event event;

        while (this->_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }
            if (_data->inputManager.IsClicked(_againBtn, sf::Mouse::Left, _data->window))
            {
                _data->stateMachine.AddState(StateRef(new GameState(_data)), true);
            }
        }
    }

    void GameOverState::Update(float dt)
    {

    }

    void GameOverState::Draw(float dt)
    {
        _data->window.clear();

        _data->window.draw(_background);
        _data->window.draw(_gameOverTitle);
        _data->window.draw(_gameOverBody);
        _data->window.draw(_againBtn);
        _data->window.draw(_scoreText);
        _data->window.draw(_highScoreText);

        this->_data->window.display();
    }
}
