//
// Created by Mac của Đạt on 2/6/25.
//

#include "Bird.h"

namespace Dat
{
    Bird::Bird(GameDataRef data) : _data(data)
    {
        birdSprite.setTexture(_data->assetManager.getTexture("Bird"));
        birdSprite.setPosition((_data->window.getSize().x / 4) - (birdSprite.getGlobalBounds().width/2), (_data->window.getSize().y / 2) - (birdSprite.getGlobalBounds().height/2));
        birdState = BIRD_STATE_STILL;
    }
    void Bird::draw()
    {
        _data->window.draw(birdSprite);
    }
    void Bird::update(float dt)
    {
        if (BIRD_STATE_FALL == birdState)
        {
            birdSprite.move(0, GRAVITY *dt);
        }else if (BIRD_STATE_FLY == birdState)
        {
            birdSprite.move(0, -FLY_SPEED *dt);
        }
        if (clock.getElapsedTime().asSeconds() > FLY_DURATION)
        {
            clock.restart();
            birdState = BIRD_STATE_FALL;
        }
    }
    void Bird::tap()
    {
        clock.restart();
        birdState = BIRD_STATE_FLY;

    }
    sf::Sprite &Bird::getSprite()
    {
        return birdSprite;
    }


}
