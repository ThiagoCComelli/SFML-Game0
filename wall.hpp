#include <SFML/Graphics.hpp>
#include "apple.hpp"

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
    Apple apple;
    vector<Apple>appleList{apple};

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
        appleList[0].shape.setPosition(shapetop.getPosition().x+10,shapetop.getGlobalBounds().height+90);

    }
    void mover(float x,float y)
    {

        shape.move(x,y);
        shapetop.move(x,y);
        if(appleList.size() == 1)
        {
            appleList[0].shape.move(x,y);
        }
    }
    void deletar()
    {
        appleList.erase(appleList.begin()+0);
    }
    void adicionar()
    {
        appleList.push_back(Apple(apple));
    }

};
