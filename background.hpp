#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Background
{
public:
    Texture texture;
    Sprite sprite;
    Background(){
        texture.loadFromFile("images/bg.png");
        sprite.setTexture(texture);
        sprite.setPosition(0,0);
    }
};

