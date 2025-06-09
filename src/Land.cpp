//
// Created by Mac của Đạt on 5/6/25.
//
#include "Land.h"
#include "Game.h"
#include"DEFINITIONS.h"
namespace Dat
{
    Land::Land(GameDataRef data): _data(data)
    {
        sf::Sprite sprite(_data->assetManager.getTexture("Land"));
        sf::Sprite sprite2(_data->assetManager.getTexture("Land"));
        sprite.setPosition(0, _data->window.getSize().y - sprite.getGlobalBounds().height);
        sprite2.setPosition(sprite.getGlobalBounds().width, _data->window.getSize().y - sprite.getGlobalBounds().height);
        _landSprites.push_back(sprite);
        _landSprites.push_back(sprite2);
    }

    void Land::moveLand(float dt)
    {
        for (int i = 0; i < _landSprites.size(); i++)
        {
            float movement = PIPE_MOVE_SPEED *dt;
            _landSprites[i].move(-movement, 0.0f);
            if (_landSprites.at(i).getPosition().x < 0 - _landSprites.at(i).getGlobalBounds().width)
            {
                sf::Vector2f position(_data->window.getSize().x, _landSprites.at(i).getPosition().y);
                _landSprites.at(i).setPosition(position);
            }
        }
    }
    void Land::drawLand()
    {
        for (int i = 0; i < _landSprites.size(); i++)
        {
            _data->window.draw(_landSprites.at(i));
        }
    }
    std::vector<sf::Sprite> &Land::getSprites()
    {
        return _landSprites;
    }
}