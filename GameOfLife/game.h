#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "constants.h"
#include "grid.h"

const int MenuCol = 750; //690 before
const int MenuRow = 50;
using namespace std;

class Game{
public:
    Game();
    void Draw();
    void run();
    void processEvents();
    void update();
    void render();
    void DrawLiveCell(int i, int j, bool life);
    void DrawGrid();
    void DrawMenu();

    bool Collision(int point1, int point2);
    void Menu1Colors(sf::Vector2i mousePos);
    void Menu2Colors(sf::Vector2i mousePos);
    void Menu3Colors(sf::Vector2i mousePos);
    void Menu4Colors(sf::Vector2i mousePos);
    void Menu5Colors(sf::Vector2i mousePos);
    void Menu6Colors(sf::Vector2i mousePos);
    void Menu7Colors(sf::Vector2i mousePos);
    void Menu8Colors(sf::Vector2i mousePos);
    void DrawSquare(int row, int col);
    void DrawButton();


    bool MouseInRectangle(sf::FloatRect r, sf::Vector2i mosuePos);


    sf::RectangleShape mybox;

private:
    //pause
    bool pause=true;
    bool set=false;
    sf::FloatRect bounds[23];
    sf::RenderWindow window;
    //2D Grid
    Grid g;
    //Text Button
    sf::Text menu1;
    sf::Text menu2;
    sf::Text menu3;
    sf::Text menu4;
    sf::Text menu5;
    sf::Text menu6;
    sf::Text menu7;
    sf::Text menu8;

    //Text Button Color
    sf::Color menu1Color;
    sf::Color menu2Color;
    sf::Color menu3Color;
    sf::Color menu4Color;
    sf::Color menu5Color;
    sf::Color menu6Color;
\
    //Button
    sf::CircleShape save1;
    sf::CircleShape save2;
    sf::CircleShape save3;
    sf::CircleShape save4;

    sf::CircleShape save5;
    sf::CircleShape save6;
    sf::CircleShape save7;

    sf::CircleShape load1;
    sf::CircleShape load2;
    sf::CircleShape load3;
    sf::CircleShape load4;
    sf::CircleShape load5;
    sf::CircleShape load6;
    sf::CircleShape load7;


};





#endif // GAME_H
