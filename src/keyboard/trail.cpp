#include <iostream>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "utilities/util.h"
#include "assets/path.h"
#include "trail.h"

namespace linthesia {
/**
 *
 */
KeyboardTrail::KeyboardTrail() {
    std::string actual_graphics_dir_path;

    if (dirExists(GRAPHICS_DIR))
    {
        actual_graphics_dir_path = GRAPHICS_DIR;
    }
    else
    {
        actual_graphics_dir_path = LOCAL_GRAPHICS_DIR;
    }
    const std::string TOP_SEPARATOR = actual_graphics_dir_path + "keyboard_top_separator.png";
    if (!texture.loadFromFile(TOP_SEPARATOR)) {
        std::cerr
            << "Can't load "
            << TOP_SEPARATOR
            << std::endl
        ;
    }

    texture.setSmooth(true);
    texture.setRepeated(true);
    sprite.setTexture(texture);
}

/**
 *
 */
void KeyboardTrail::setWidth(const int width) {
    sprite.setTextureRect(sf::IntRect(
        0,
        0,
        width,
        static_cast<int>(texture.getSize().y)
    ));
}


/**
 *
 */
const sf::FloatRect KeyboardTrail::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}

/**
 *
 */
void KeyboardTrail::draw(
    sf::RenderTarget& target,
    sf::RenderStates states
) const {
    states.transform *= getTransform();
    target.draw(sprite, states);
}

} // end of namespace

