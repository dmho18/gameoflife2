#include "game.h"
#include "grid.h"
#include "ResourcePath.hpp"
#include <iostream>

const int cellSize=10;  //size of each size
Game::Game(){

    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "DANH HO~~~~");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.
    window.setFramerateLimit(5);
}

void Game::Draw(){
    //Look at the data and based on the data, draw shapes on window object.
    DrawMenu();
    DrawGrid();
    DrawButton();
}
void Game::DrawLiveCell(int row,int col, bool life){
//  cell is a rectangle with size 10x10
    sf::RectangleShape cell(sf::Vector2f(cellSize,cellSize));
    cell.setPosition(row,col);
    sf::Color mediumSlateBlue(123,104,238);
    if(life){
        //if cell is alive, set cell's color to Cyan
        cell.setFillColor(sf::Color::Cyan);
        window.draw(cell);
    }
    else{
        //dead cell is set to Blue
        cell.setFillColor(mediumSlateBlue);
        window.draw(cell);
    }
}
void Game::DrawButton(){   //Save pattern button
    int ButtonCol = MenuCol+155;
    int ButtonRow = MenuRow+70;

//    save1.setRadius(15);
//    save1.setPointCount(6);
//    save1.setFillColor(sf::Color(255,225,230));
//    save1.setPosition(sf::Vector2f(ButtonCol,ButtonRow));
//    bounds[8] = save1.getGlobalBounds();
//    window.draw(save1);
//
//
//    save2.setRadius(15);
//    save2.setPointCount(6);
//    save2.setFillColor(sf::Color(255,203,211));
//    save2.setPosition((sf::Vector2f(ButtonCol+30,(ButtonRow))));
//    bounds[9] = save2.getGlobalBounds();
//    window.draw(save2);
//
//    save4.setRadius(15);
//    save4.setPointCount(6);
//    save4.setFillColor(sf::Color(255,196,205));
//    save4.setPosition((sf::Vector2f(ButtonCol+16,(ButtonRow+25))));
//    bounds[11] = save4.getGlobalBounds();
//    window.draw(save4);
//
//    save5.setRadius(15);
//    save5.setPointCount(6);
//    save5.setFillColor(sf::Color(255,182,193));
//    save5.setPosition((sf::Vector2f(ButtonCol+45,(ButtonRow+25))));
//    bounds[12] = save5.getGlobalBounds();
//    window.draw(save5);
//
//    save3.setRadius(15);
//    save3.setPointCount(6);
//    save3.setFillColor(sf::Color(255,218,224));
//    save3.setPosition((sf::Vector2f(ButtonCol-13,(ButtonRow+25))));
//    bounds[10] = save3.getGlobalBounds();
//    window.draw(save3);
//
//    save6.setRadius(15);
//    save6.setPointCount(6);
//    save6.setFillColor(sf::Color(255,211,217));
//    save6.setPosition((sf::Vector2f(ButtonCol,(ButtonRow+50))));
//    bounds[13] = save6.getGlobalBounds();
//    window.draw(save6);
//
//    save7.setRadius(15);
//    save7.setPointCount(6);
//    save7.setFillColor(sf::Color(255,189,199));
//    save7.setPosition((sf::Vector2f(ButtonCol+30,(ButtonRow+50))));
//    bounds[14] = save7.getGlobalBounds();
//    window.draw(save7);
//
//    load1.setRadius(15);
//    load1.setPointCount(6);
//    load1.setFillColor(sf::Color(244,233,255));
//    load1.setPosition(sf::Vector2f(ButtonCol,(ButtonRow*3+10))) ;
//    bounds[15] = load1.getGlobalBounds();
//    window.draw(load1);
//
//    load2.setRadius(15);
//    load2.setPointCount(6);
//    load2.setFillColor(sf::Color(234,211,255));
//    load2.setPosition(sf::Vector2f(ButtonCol+30,(ButtonRow*3+10))) ;
//    bounds[16] = load2.getGlobalBounds();
//    window.draw(load2);
//
//    load3.setRadius(15);
//    load3.setPointCount(6);
//    load3.setFillColor(sf::Color(241,225,255));
//    load3.setPosition(sf::Vector2f(ButtonCol-13,(ButtonRow*3+35))) ;
//    bounds[17] = load3.getGlobalBounds();
//    window.draw(load3);
//
//    load4.setRadius(15);
//    load4.setPointCount(6);
//    load4.setFillColor(sf::Color(231,203,255));
//    load4.setPosition(sf::Vector2f(ButtonCol+16,(ButtonRow*3+10)+25)) ;
//    bounds[18] = load4.getGlobalBounds();
//    window.draw(load4);
//
//    load5.setRadius(15);
//    load5.setPointCount(6);
//    load5.setFillColor(sf::Color(224,189,255));
//    load5.setPosition(sf::Vector2f(ButtonCol+45,(ButtonRow*3+10)+25)) ;
//    bounds[19] = load5.getGlobalBounds();
//    window.draw(load5);
//
//    load6.setRadius(15);
//    load6.setPointCount(6);
//    load6.setFillColor(sf::Color(238,218,255));
//    load6.setPosition(sf::Vector2f(ButtonCol,(ButtonRow*3+10)+50)) ;
//    bounds[20] = load6.getGlobalBounds();
//    window.draw(load6);
//
//    load7.setRadius(15);
//    load7.setPointCount(6);
//    load7.setFillColor(sf::Color(227,196,255));
//    load7.setPosition(sf::Vector2f(ButtonCol+30,(ButtonRow*3+10)+50)) ;
//    bounds[21] = load7.getGlobalBounds();
//    window.draw(load7);

}

void Game::DrawGrid(){      //Draw Grid
    int row;
    int col;
    for(int i=2;i<MAX-2;i++){
        for(int j=2;j<MAX-2;j++){
            //i and j are translated into col and row
            row = j*cellSize+(j+1);
            col = i*cellSize+(i+1);
            //draw each live cell at given row and col
            DrawLiveCell(row,col,g.getAtCoords(i,j));
        }
    }
}

void Game::update()
{
    //if pause, dont do anything
    if(pause==true){
        return;
    }
    else{ //else, generate next step
        g.Step();
    }
}

void Game::render(){
       window.clear(sf::Color(0,204,204));
       Draw();
       window.display();
}

void Game::processEvents()
{
   sf::Event event;
   while (window.pollEvent(event))//or waitEvent
   {
       //get the position of the mouse
       //because can't do it in switch
       sf::Vector2i position = sf::Mouse::getPosition(window);

       // check the type of the event...
       switch (event.type)
       {
           // window closed
           // "close requested" event: we close the window
           case sf::Event::MouseMoved:
           //Change color if mouse is in the region of text button
            Menu1Colors(position);
            Menu2Colors(position);
            Menu3Colors(position);
            Menu4Colors(position);
            Menu5Colors(position);
            Menu6Colors(position);
            cout<<"("<<position.x<<", "<<position.y<<")"<<endl;
           break;
           case sf::Event::Closed:
               window.close();
               break;

           // key pressed
           case sf::Event::KeyPressed:{
                cout<<"key press"<<endl;
                if( event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }

               if( event.key.code == sf::Keyboard::R){ //populate random when r is pressed
                   g.PopulateRandom(300);
               }
               if( event.key.code == sf::Keyboard::C){ //clear when click C
                   std::cout<<"CLEAR........"<<std::endl;
                   g.Clear();       //call bool pause
               }
               if( event.key.code == sf::Keyboard::Space){// pause/play when press space bar
                   std::cout<<"SPACE BAR........"<<std::endl;
                   pause=!pause;
               }
               if( event.key.code == sf::Keyboard::S){ //save when s is pressed
                   std::cout<<"SAVING........"<<std::endl;
                   g.Save("GameOfLife.txt");    //call function Save() from grid class
               }
               if( event.key.code == sf::Keyboard::L){ //load when l is pressed
                   std::cout<<"LOADING........"<<std::endl;
                   pause=true;
                   g.LoadPattern1("Pattern1.txt");    //call function Load() from grid class
               }

//               break;
//           case sf::Event::MouseButtonPressed:{
               int j= (event.mouseButton.x)/(cellSize+1);
               int i=(event.mouseButton.y)/(cellSize+1);
               
               cout<<"mouse button "<<sf::Mouse::Left<<endl;
               if(event.mouseButton.button == sf::Mouse::Left){
                   cout<<"key and mouse pressed"<<endl;
               }
               
                if( sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && event.key.code == sf::Keyboard::LShift) {
                        std::cout<<"left shift"<<std::endl;
                        g.SetFirstX(i);
                        g.SetFirstY(j);
                        std::cout<<"first location: ("<<g.GetFirstX()<<", "<<g.GetFirstY()<<")"<<std::endl;
                }
//                    if( event.key.code ==sf::Keyboard::LShift){
//                        std::cout<<"left shift"<<std::endl;
//                        g.SetFirstX(i);
//                        g.SetFirstY(j);
//                        std::cout<<"first location: ("<<g.GetFirstX()<<", "<<g.GetFirstY()<<")"<<std::endl;
//                    }
                if( event.mouseButton.button == sf::Mouse::Left && event.key.code == sf::Keyboard::LControl){
                        std::cout<<"left control"<<std::endl;
                        g.SetCursorX(i);
                        g.SetCursorY(j);
                        std::cout<<"set cursor: ("<<g.GetCursorX()<<", "<<g.GetCursorY()<<")"<<std::endl;

                }
           
               break;
       }
           case sf::Event::MouseButtonReleased:     //press mouse
               if (event.mouseButton.button == sf::Mouse::Right){   //press right mouse
                   std::cout << "the right button was pressed" << std::endl;
                   std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                   std::cout << "mouse y: " << event.mouseButton.y << std::endl;

               }
               if(event.mouseButton.button == sf::Mouse::Left){ //press left mouse
                   std::cout << "Is it you? Left?" << std::endl;
                   cout<<"("<<event.mouseButton.x<<", "<<event.mouseButton.y<<")"<<endl;    //give position

                   //translate from window cow and rol to grid i and j
                   int j= (event.mouseButton.x)/(cellSize+1);
                   int i=(event.mouseButton.y)/(cellSize+1);

                    if(event.key.code == sf::Keyboard::LShift){
                        g.SetLastX(i);
                        g.SetLastY(j);
                       cout<<"last coord :("<<g.GetLastX()<<", "<<g.GetLastY()<<")"<<endl;
                    }
                    if(MouseInRectangle(bounds[8],position)){
                         std::cout<<"Save pattern 1 button was pressed!"<<std::endl;
                         g.SavePattern1("Pattern1.txt");
                    }
                    if(MouseInRectangle(bounds[9],position)){
                         std::cout<<"Save pattern 2 button was pressed!"<<std::endl;
                         g.SavePattern1("Pattern2.txt");
                    }
                    if(MouseInRectangle(bounds[10],position)){
                         std::cout<<"Save pattern 3 button was pressed!"<<std::endl;
                         g.SavePattern1("Pattern3.txt");
                    }
                    if(MouseInRectangle(bounds[11],position)){
                         std::cout<<"Save pattern 4 button was pressed!"<<std::endl;
                         g.SavePattern1("Pattern4.txt");
                    }
                    if(MouseInRectangle(bounds[12],position)){
                         std::cout<<"Save pattern 5 button was pressed!"<<std::endl;
                         g.SavePattern1("Pattern5.txt");
                    }
                    if(MouseInRectangle(save6.getGlobalBounds(),position)){
                         std::cout<<"Save pattern 6 button was pressed!"<<std::endl;
                         g.SavePattern1("Pattern6.txt");
                    }
                    if(MouseInRectangle(save7.getGlobalBounds(),position)){
                         std::cout<<"Save pattern 7 button was pressed!"<<std::endl;
                         g.SavePattern1("Pattern7.txt");
                    }






                   //if left mouse is clicked
                   //and inside the grid
                   if(i<=MAX&&j<=MAX&& event.key.code != sf::Keyboard::LShift){

                       //pause first or the cell dies right away
                       pause=true;
                       if(g.getAtCoords(i,j)){  //if cell is alve
                           cout<<"Killing at ["<<i<<", "<<j<<"]"<<endl;
                           g.Kill(i,j);     //kill
                       }
                       else {    //if cell is dead
                           cout<<"Setting Alive at ["<<i<<", "<<j<<"]"<<endl;
                           g.SetAlive(i,j); //bring cell back to life
                       }
                   }
                   else{    //left mouse is clicked outside of grid range
                       //call function Save() from Grid
                       //if the mouse is in the region of the text 1 box
                       if(MouseInRectangle(bounds[0],position)){
                           std::cout<<"Save button was pressed!"<<std::endl;
                           g.Save("GameOfLife.txt");
                       }
                       //check with the second text box
                       // for Load
                       if(MouseInRectangle(bounds[1],position)){
                           std::cout<<"Load button was pressed!"<<std::endl;
                            g.Load("GameOfLife.txt");
                            pause=true;
                       }
                       //third
                       //for Random
                       if(MouseInRectangle(bounds[2],position)){
                           std::cout<<"Random button was pressed!"<<std::endl;
                           pause=true;
                           g.PopulateRandom(50);
                       }
                       //fourth
                       //for Clear
                       if(MouseInRectangle(bounds[3],position)){
                           std::cout<<"Clear button was pressed!"<<std::endl;
                           g.Clear();
                       }
                       //fifth
                       //for Step
                       if(MouseInRectangle(bounds[4],position)){
                           std::cout<<"Step button was pressed!"<<std::endl;
                           pause=true;
                           g.Step();
                       }
                       //sixth
                       //for Go
                       if(MouseInRectangle(bounds[5],position)){
                           std::cout<<"Go button was pressed!"<<std::endl;
                           if(pause==true){
                               cout<<"Run!"<<endl;
                               pause=!pause;
                           }
                       }
                       if(MouseInRectangle(load1.getGlobalBounds(),position)){
                           std::cout<<"Load pattern 1!"<<std::endl;
                           g.LoadPattern1("Pattern1.txt");
                       }
                       if(MouseInRectangle(load2.getGlobalBounds(),position)){
                           std::cout<<"Load pattern 2!"<<std::endl;
                           g.LoadPattern1("Pattern2.txt");
                       }
                       if(MouseInRectangle(load3.getGlobalBounds(),position)){
                           std::cout<<"Load pattern 3!"<<std::endl;
                           g.LoadPattern1("Pattern3.txt");
                       }
                       if(MouseInRectangle(load4.getGlobalBounds(),position)){
                           std::cout<<"Load pattern 4!"<<std::endl;
                           g.LoadPattern1("Pattern4.txt");
                       }
                       if(MouseInRectangle(load5.getGlobalBounds(),position)){
                           std::cout<<"Load pattern 5!"<<std::endl;
                           g.LoadPattern1("Pattern5.txt");
                       }
                       if(MouseInRectangle(load6.getGlobalBounds(),position)){
                           std::cout<<"Load pattern 6!"<<std::endl;
                           g.LoadPattern1("Pattern6.txt");
                       }
                       if(MouseInRectangle(load7.getGlobalBounds(),position)){
                           std::cout<<"Load pattern 7!"<<std::endl;
                           g.LoadPattern1("Pattern7.txt");
                       }

                    }
               }
               break;

           default:
               break;
       }
   }
}

void Game::run()
{

   while (window.isOpen())
   {

       Draw();

       processEvents();
       update();
       render(); //clear/draw/display
   }
}
void Game::DrawMenu(){          //Draw All the Menu button
    //create font and apply to text button
    sf::Font font;
    font.loadFromFile(resourcePath() + "sansation.ttf");

    set = true;
    //Draw menu 1
//    std::cout<<menu1<<std::endl;

    sf::Text temp;

    menu1.setFont(font);    //set font
    menu1.setStyle(sf::Text::Bold);     //set bold
    menu1.setString("Save");            //text name
    menu1.setColor(menu1Color);         //text color
    menu1.setPosition(sf::Vector2f(MenuCol,MenuRow));   //set position
    menu1.setCharacterSize(40u);        //set size
    bounds[0] = menu1.getGlobalBounds();

    window.draw(menu1);                 //draw
//
    //Draw menu 2
    //same with draw menu 1
    menu2.setFont(font);
    menu2.setStyle(sf::Text::Bold);
    menu2.setString("Load");
    menu2.setColor(menu2Color);
    menu2.setPosition(sf::Vector2f(MenuCol,MenuRow*3));
    menu2.setCharacterSize(40u);
    bounds[1] = menu2.getGlobalBounds();
    window.draw(menu2);
    

    //draw menu 3
    menu3.setFont(font);
    menu3.setStyle(sf::Text::Bold);
    menu3.setString("Random");
    menu3.setColor(menu3Color);
    menu3.setPosition(sf::Vector2f(MenuCol-25,MenuRow*5));
    menu3.setCharacterSize(40u);
    bounds[2] = menu3.getGlobalBounds();
    window.draw(menu3);

    //draw menu 4
    menu4.setFont(font);
    menu4.setStyle(sf::Text::Bold);
    menu4.setString("Clear");
    menu4.setColor(menu4Color);
    menu4.setPosition(sf::Vector2f(MenuCol,MenuRow*7));
    menu4.setCharacterSize(40u);
    bounds[3] = menu4.getGlobalBounds();
    window.draw(menu4);

    //draw menu 5
    menu5.setFont(font);
    menu5.setStyle(sf::Text::Bold);
    menu5.setString("Step");
    menu5.setCharacterSize(24);
    menu5.setColor(menu5Color);
    menu5.setPosition(sf::Vector2f(MenuCol,MenuRow*9));
    menu5.setCharacterSize(40u);
    bounds[4] = menu5.getGlobalBounds();
    window.draw(menu5);

    //draw menu 6
    menu6.setFont(font);
    menu6.setStyle(sf::Text::Bold);
    menu6.setString("Go");
    menu6.setColor(menu6Color);
    menu6.setPosition(sf::Vector2f(MenuCol+20,MenuRow*11));
    menu6.setCharacterSize(40u);
    bounds[5] = menu6.getGlobalBounds();
    window.draw(menu6);

//    //draw menu 7
//    menu7.setFont(font);
//    menu7.setStyle(sf::Text::Bold);
//    menu7.setString("Save Pattern");
//    menu7.setColor(sf::Color(0,0,128));
//    menu7.setPosition(sf::Vector2f(MenuCol+130,(MenuRow+10)));
//    menu7.setCharacterSize(20u);
////    bounds[6] = menu7.getGlobalBounds();
//    window.draw(menu7);
//
//    //draw menu 8
//    menu8.setFont(font);
//    menu8.setStyle(sf::Text::Bold);
//    menu8.setString("Load Pattern");
//    menu8.setColor(sf::Color(0,0,128));
//    menu8.setPosition(sf::Vector2f(MenuCol+130,(MenuRow)*6+10));
//    menu8.setCharacterSize(20u);
//    bounds[7] = menu8.getGlobalBounds();
    window.draw(menu8);
}

bool Game::MouseInRectangle(sf::FloatRect r, sf::Vector2i mousePos){    //check if mouse is in the region of of bounding box (text, sprite1...)
    //because r.contains() won't take vector2i, I change it to vector2f
    std::cout<<"position: "<<std::endl;

    sf::Vector2f point;
    point.x=mousePos.x;
    point.y=mousePos.y;
    //if the bounding box contains mouse position
    if(r.contains(point)){
        return true;
    }
    return false;
}

void Game::Menu1Colors(sf::Vector2i mousePos){
    //x and y are mouse pos.
    //change color of text for the menu items to white or blue
    //  depending if the mouse pointer is in the respective box.

        //calls MouseInRectangle()
    if (MouseInRectangle(bounds[0], mousePos)){
        menu1Color = sf::Color::White;  //set white if mouse is in the box
    }
    else{
        menu1Color = sf::Color(0,0,128);    //else set it to dark blue
    }

}
void Game::Menu2Colors(sf::Vector2i mousePos){  //The same function that operate like Menu1Colors()

    if(!set){   //menu hasn't been drawn
        return;
    }

    if(MouseInRectangle(bounds[1],mousePos)){
        menu2Color = sf::Color::White;      //the only difference is that the private variable changes
    }
    else{
        menu2Color = sf::Color(0,0,128);
    }
}
void Game::Menu3Colors(sf::Vector2i mousePos){      //same with Menu1Colors

    if(!set){   //menu hasn't been drawn
        return;
    }

    if(MouseInRectangle(bounds[2],mousePos)){
        menu3Color = sf::Color::White;
    }
    else{
        menu3Color = sf::Color(0,0,128);
    }
}
void Game::Menu4Colors(sf::Vector2i mousePos){      //same with Menu1Colors
    if(!set){   //menu hasn't been drawn
        return;
    }

    if(MouseInRectangle(bounds[3],mousePos)){
        menu4Color = sf::Color::White;
    }
    else{
        menu4Color = sf::Color(0,0,128);
    }
}
void Game::Menu5Colors(sf::Vector2i mousePos){      //same with Menu1Colors
    if(!set){   //menu hasn't been drawn
        return;
    }

    if(MouseInRectangle(bounds[4],mousePos)){
        menu5Color = sf::Color::White;
    }
    else{
        menu5Color = sf::Color(0,0,128);
    }
}
void Game::Menu6Colors(sf::Vector2i mousePos){      //same with Menu1Colors
    if(!set){   //menu hasn't been drawn
        return;
    }

    if(MouseInRectangle(bounds[5],mousePos)){
        menu6Color = sf::Color::White;
    }
    else{
        menu6Color = sf::Color(0,0,128);
    }
}

