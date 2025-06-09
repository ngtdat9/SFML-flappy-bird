//
// Created by Mac của Đạt on 9/6/25.
//
#include "displayHUD.h"
#include<string>
namespace Dat
{
    DisplayHUD::DisplayHUD(GameDataRef data) : _data(data)
    {
        _scoreText.setFont(_data->assetManager.getFont("Flappy Font"));
        _scoreText.setString("0");
        _scoreText.setCharacterSize(128);
        _scoreText.setFillColor(sf::Color::White);
        _scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);
        _scoreText.setPosition(_data->window.getSize().x /2, _data->window.getSize().y / 5);
    }

    void DisplayHUD::draw()
    {
        _data->window.draw(_scoreText);
    }

    void DisplayHUD::updateScore(int score)
    {
        _scoreText.setString(std::to_string(score));
    }
}