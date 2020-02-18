#include <SFML/Graphics.hpp>
#include "stage0.hpp"


using namespace sf;
using namespace std;


class Menu
{
public:
    int start()
    {
        RenderWindow window(VideoMode(w, h), "Game! [MENU]");
        window.setFramerateLimit(60);
        Font font;
        font.loadFromFile("arial.ttf");

        RectangleShape buttonStart;
        RectangleShape buttonExit;
        vector<RectangleShape>buttonList;

        Text textStart;
        Text textExit;
        vector<Text>textList;

        Stage stage;
        vector<Stage>stageList{stage};

        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                {
                    window.close();
                }
                else if(event.type == Event::MouseButtonReleased)
                {
                    if( 100 < int(Mouse::getPosition(window).x) && int(Mouse::getPosition(window).x) < 200
                            && 50 < int(Mouse::getPosition(window).y) && 90 > int(Mouse::getPosition(window).y))
                    {
                        stageList[0].start();
                        stageList.erase(stageList.begin()+0);
                        stageList.push_back(Stage(stage));

                    }
                    else if( 250 < int(Mouse::getPosition(window).x) && int(Mouse::getPosition(window).x) < 350
                             && 50 < int(Mouse::getPosition(window).y) && 90 > int(Mouse::getPosition(window).y))
                    {
                        window.close();
                    }
                }
            }

            /// BUTTONS ///

            buttonStart.setFillColor(Color::Red);
            buttonStart.setPosition(100,50);
            buttonStart.setSize(Vector2f(100,40));

            buttonExit.setFillColor(Color::Red);
            buttonExit.setPosition(250,50);
            buttonExit.setSize(Vector2f(100,40));

            buttonList.push_back(buttonStart);
            buttonList.push_back(buttonExit);

            textStart.setFont(font);
            textStart.setColor(Color::White);
            textStart.setCharacterSize(30);
            textStart.setString("Start");
            textStart.setPosition(115,50);

            textExit.setFont(font);
            textExit.setColor(Color::White);
            textExit.setCharacterSize(30);
            textExit.setString("Exit");
            textExit.setPosition(270,50);

            textList.push_back(textStart);
            textList.push_back(textExit);

            /// DRAW ///

            window.clear();

            for(int i = 0; i<int(buttonList.size()); i++)
            {
                window.draw(buttonList[i]);
            }

            for(int i = 0; i<int(textList.size()); i++)
            {
                window.draw(textList[i]);
            }

            window.display();

        }
        return 0;
    }

};


