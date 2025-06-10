//
// Created by Mac của Đạt on 2/6/25.
//

#include <SFML/Graphics.hpp>
#include <SFML/System/FileInputStream.hpp>
#include <stdexcept>
#include "AssetManager.h"

namespace Dat {

    void AssetManager::loadTexture(std::string name, std::string fileName){
        sf::FileInputStream stream;
        if (!stream.open(fileName)) {
            throw std::runtime_error("Failed to open texture file: " + fileName);
        }

        sf::Texture texture;
        if (!texture.loadFromStream(stream)) {
            throw std::runtime_error("Failed to load texture from stream: " + fileName);
        }

        _textures[name] = std::move(texture);
    }

    sf::Texture& AssetManager::getTexture(const std::string& name){
        return _textures.at(name);
    }

    void AssetManager::loadFont(std::string name, std::string fileName){
        sf::Font font;

        if (font.loadFromFile(fileName))
        {
            this->_fonts[name] = font;
        }
    }

    sf::Font& AssetManager::getFont(std::string name){
        return this->_fonts.at(name);
    }
}
