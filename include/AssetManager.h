#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

namespace Dat {
    class AssetManager {
    public:
        AssetManager() = default;
        ~AssetManager() = default;

        void loadTexture(std::string name, std::string fileName);
        sf::Texture& getTexture(const std::string& name);

        void loadFont(std::string name, std::string fileName);
        sf::Font& getFont(std::string name);

    private:
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Font> _fonts;
    };
}
