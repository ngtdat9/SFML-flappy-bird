//
// Created by Mac của Đạt on 2/6/25.
//

#include "Pipe.h"
#include<iostream>
#include "DEFINITIONS.h"

namespace Dat
{
    Pipe::Pipe(GameDataRef data) :_data(data)
    {
        landHeight = _data->assetManager.getTexture("Land").getSize().y;
        pipe_y = 0;
    }
    void Pipe::SpawnTopPipe()
    {
        sf::Sprite sprite(_data->assetManager.getTexture("Pipe Down"));
        sprite.setPosition(_data->window.getSize().x, -pipe_y);
        pipes.push_back(sprite);
    }
    void Pipe::SpawnBottomPipe()
    {
        sf::Sprite sprite(_data->assetManager.getTexture("Pipe Up"));
        sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height - pipe_y);
        pipes.push_back(sprite);
    }


    void Pipe::SpawnScorePipe()
    {
        sf::Sprite sprite(_data->assetManager.getTexture("Scoring Pipe"));
        sprite.setPosition(_data->window.getSize().x, 0);
        sprite.setColor(sf::Color(0,0,0,0));
        scorePipes.push_back(sprite);
    }

    void Pipe::movePipes(float dt)
    {
        for (int i= 0; i < pipes.size(); i++)
        {
            if (pipes[i].getPosition().x < 0 - pipes[i].getGlobalBounds().width)
            {
                pipes.erase(pipes.begin() + i);
            }else
            {
                float movement = PIPE_MOVE_SPEED * dt;
                pipes.at(i).move(-movement, 0);
            }
        }

        for (int i= 0; i < scorePipes.size(); i++)
        {
            if (scorePipes[i].getPosition().x < 0 - scorePipes[i].getGlobalBounds().width)
            {
                scorePipes.erase(scorePipes.begin() + i);
            }else
            {
                float movement = PIPE_MOVE_SPEED * dt;
                scorePipes.at(i).move(-movement, 0);
            }
        }
    }
    void Pipe::DrawPipes()
    {
        for (int i= 0; i < pipes.size(); i++)
        {
            _data->window.draw(pipes.at(i));
        }
    }
    void Pipe::randomPipes()
    {
        // Random vertical offset for pipes: 1 <= pipe_y <= landHeight
        pipe_y = rand() % (landHeight + 1);
    }
     std::vector<sf::Sprite> &Pipe::getSprites()
    {
        return pipes;
    }
    std::vector<sf::Sprite> &Pipe::getScorePipes()
    {
        return scorePipes;
    }
}
