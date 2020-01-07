#include <SFML/Graphics.hpp>
#include "variables.hpp"

using namespace std;
using namespace sf;

class Player
{
private:
    int points = 0;
public:
    Texture green;
    RectangleShape shape;
    Player(){
        green.loadFromFile("images/red.png");
        shape.setSize(Vector2f(20.f,20.f));
        shape.setFillColor(Color::White);
        shape.setPosition(w/2-10,h/2-10);
        shape.setTexture(&green);
    }
    void pointsCC(){
        points++;
    }
    void resetPoints(){
        points = 0;
    }
    int getPoints(){
        return points;
    }
};


