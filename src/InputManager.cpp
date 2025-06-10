#include "InputManager.h"

namespace Dat
{
    bool InputManager::IsClicked(sf::Sprite obj, sf::Mouse::Button button, sf::RenderWindow& window)
    {
        if (sf::Mouse::isButtonPressed(button))
        {
            sf::IntRect playButtonRect(obj.getPosition().x, obj.getPosition().y, obj.getGlobalBounds().width, obj.getGlobalBounds().height);
            if (playButtonRect.contains(sf::Mouse::getPosition(window)))
            {
                return true;
            }
        }
        return false;
    }
}
