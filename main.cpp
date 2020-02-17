#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "wall.hpp"
#include "background.hpp"
#include "score.hpp"


using namespace sf;
using namespace std;


int main()
{
    RenderWindow window(VideoMode(w, h), "Game!");
    window.setFramerateLimit(60);

    Player player;
    Wall wall;
    Background background;
    Score score;
    Text text;
    Font font;

    font.loadFromFile("arial.ttf");

    text.setFont(font);
    text.setColor(Color::White);
    text.setCharacterSize(30);
    text.setString(score.getText(player.getPoints(),0));




    vector<Background>backList;
    for(int i = 0; i<5; i++)
    {
        backList.push_back(Background(background));
        backList[i].sprite.setPosition(b+=360,0);
    }


    vector<Wall>wallList;
    for(int i = 0; i<6; i++)
    {
        wallList.push_back(Wall(wall));
        wallList[i].shape.setPosition(a+=(-160),h);
        wallList[i].shapetop.setPosition(a,0);
        wallList[i].updateTam();
    }



    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            else if ((event.type == Event::KeyReleased) && (event.key.code == Keyboard::Up))
            {
                isAir = true;
                isJump = true;
                gravity = 7;
                velB = 5;
            }
        }

        if(!gameOver)
        {
            /// MOVE ///

            if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                if(player.shape.getPosition().y > 0)
                {
                    velB *= 0.9;

                    if(velB > 0.3)
                    {
                        player.shape.move(0,-vel*velB);
                    }
                    else
                    {
                        isJump = true;
                    }
                }
            }

            if(isJump)
            {
                if(player.shape.getPosition().y < h-20)
                {
                    player.shape.move(0,gravity*=1.012);
                }
                else
                {
                    isJump = !isJump;
                }
            }

            /// BACKGROUND MOVE ///

            for(int i = 0; i<int(backList.size()); i++)
            {
                backList[i].sprite.move(1,0);
                if((backList[i].sprite.getPosition().x) > w+360)
                {
                    backList[i].sprite.setPosition(-359,0);
                }
            }

            /// PLAYER && APPLE ///
            for(int i = 0; i<int(wallList.size()); i++)
            {
                if(wallList[i].appleList.size() == 1)
                {
                    if(player.shape.getGlobalBounds().intersects(wallList[i].appleList[0].shape.getGlobalBounds()))
                    {
                        wallList[i].deletar();
                        player.pointsCC();
                        text.setString(score.getText(player.getPoints(),0));

                    }
                }
            }

            /// PLAYER && WALL ///
            for(int i = 0; i<int(wallList.size()); i++)
            {
                if(player.shape.getGlobalBounds().intersects(wallList[i].shape.getGlobalBounds()) ||
                        player.shape.getGlobalBounds().intersects(wallList[i].shapetop.getGlobalBounds()))
                {
                    gameOver = !gameOver;
                }
            }


            /// RECTANGLE ///

            for(int i =0; i<int(wallList.size()); i++)
            {
                wallList[i].mover(3,0);
                if(wallList[i].shape.getPosition().x > w)
                {
                    wallList[i].shape.setPosition(-40,wallList[i].shape.getPosition().y);
                    wallList[i].shapetop.setPosition(-40,wallList[i].shapetop.getPosition().y);
                    if (wallList[i].appleList.size() == 0)
                    {
                        wallList[i].adicionar();
                    }
                    wallList[i].updateTam();
                }
            }
            /// REPAIR POSITION ///

            if((player.shape.getPosition().y) > h-20)
            {
                player.shape.setPosition(player.shape.getPosition().x,h-20);
            }

            text.setCharacterSize(30);
            text.setPosition(0,0);
            text.setString(score.getText(player.getPoints(),0));

            /// DRAW ///

            window.clear();


            for(int i = 0; i<int(backList.size()); i++)
            {
                window.draw(backList[i].sprite);
            }

            window.draw(player.shape);

            for(int i = 0; i<int(wallList.size()); i++)
            {
                window.draw(wallList[i].shape);
                window.draw(wallList[i].shapetop);
                if(wallList[i].appleList.size() == 1)
                {
                    window.draw(wallList[i].appleList[0].shape);
                }
            }



            window.draw(text);

            window.display();
        }
        else
        {
            text.setString(score.getText(player.getPoints(),1));
            text.setPosition((w-text.getGlobalBounds().width)/2,(h-text.getGlobalBounds().height-40)/2);
            text.setCharacterSize(80);

            window.clear();

            window.draw(text);

            window.display();
        }
    }

    return 0;
}

