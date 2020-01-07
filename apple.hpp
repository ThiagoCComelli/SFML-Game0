#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Apple
{
private:
    int pos_x,pos_y;

public:
    Texture texture;
    RectangleShape shape;

    Apple()
    {
        texture.loadFromFile("images/red.png");
        shape.setTexture(&texture);
        srand(time(0));
        shape.setSize(Vector2f(20.f,20.f));
        shape.setFillColor(Color::Green);
    }

};

