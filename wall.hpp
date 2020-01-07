#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Wall
{
private:
    int pos_x=0,pos_y=h,tamX=40,tamY=0;
public:
    Texture texture;
    RectangleShape shape;
    RectangleShape shapetop;

    Wall()
    {
        texture.loadFromFile("images/red.png");
        srand(time(0));
        shape.setFillColor(Color::Green);
        shape.setPosition(pos_x,pos_y);
        shapetop.setFillColor(Color::Green);
        shapetop.setPosition(pos_x,0);
        shape.setTexture(&texture);
        shapetop.setTexture(&texture);


    }
    void updateTam()
    {
        tamY = (rand() % 300+(-400));
        shape.setSize(Vector2f(tamX,tamY));
        shapetop.setSize(Vector2f(tamX,(h+tamY-200)));

    }




};
