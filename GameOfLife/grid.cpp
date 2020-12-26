#include "grid.h"
#include "random.h"
#include "game.h"
#include <iostream>
#include <fstream>
using namespace std;
Grid::Grid()
{
    Init();
}
void Grid::Init(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            grid[i][j]=0;
        }
    }
}
void Grid::Print(){
    for(int i=0; i<MAX; i++){
        for(int j=0;j<MAX;j++){
            if(grid[i][j]==1){
                cout<<"*"<<" ";
            }
            else{
                cout<<"-"<<" ";
            }
        }
        cout<<endl;
    }
}
int Grid::CountNeigbors(int row, int col){
    int count=0;
    for(int i=row-1; i<row+2;i++){
        for(int j=col-1;j<col+2;j++){
            count+=grid[i][j];
        }
    }
    return count-grid[row][col];
}
bool Grid::IsAlive(int i,int j){
    int count = CountNeigbors(i,j);
    if(grid[i][j]==1){
        if(count<2||count>3){
             return false;
         }
            return true;
    }
    else{
        if(count==3){
            return true;
        }
        return false;
    }
}
void Grid::Step(){
    int a[MAX][MAX];
    //need to make a copy first otherwise it won't process correctly
    for(int i=1;i<MAX-1;i++){
        for(int j=1;j<MAX-1;j++){
            if(IsAlive(i,j)){
                a[i][j]=1;
            }
            else{
                a[i][j]=0;
            }
        }
    }
    for(int i=1;i<MAX-1;i++){
        for(int j=1;j<MAX-1;j++){
            grid[i][j]=a[i][j];
        }

    }
}
void Grid::SetAlive(int i, int j){
    grid[i][j]=1;
}
void Grid::Kill(int i, int j){
    grid[i][j]=0;
}
void Grid::Clear(){
    Init();
}
void Grid::PopulateRandom(int n){
    Random r;
    int i;
    int j;
    for(int a=0;a<n;a++){
       i = r.GetNext(0,MAX-2);
       j = r.GetNext(0,MAX-2);
       SetAlive(i,j);
    }

}

void Grid::Save(char fileName[]){
    ofstream outFile;
    outFile.open(fileName);
    if(outFile.fail()){
        cout<<"couldn't open input file...."<<endl;
        exit(0);
    }

    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){

            outFile<<grid[i][j]<<" ";
        }
        outFile<<endl;
    }
    outFile.close();
}

void Grid::Load(char fileName[]){
    ifstream inFile;
    inFile.open(fileName);
    if(inFile.fail()){
        cout<<"could not open file...."<<endl;
        exit(0);
    }
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            inFile>>grid[i][j];
        }
    }
    inFile.close();
}
int Grid::getAtCoords(int i, int j){
    return grid[i][j];
}
void Grid::SavePattern1(char fileName[]){
    ofstream outFile;
    outFile.open(fileName);
    if(outFile.fail()){
        cout<<"couldn't open input file...."<<endl;
        exit(0);
    }
    int width = lastY- firstY;
    int length = lastX - firstX;
    outFile<<length<<" ";
    outFile<<width<<" ";
    for(int i=firstX; i<=lastX; i++){
        for(int j=firstY; j<=lastY; j++){
            outFile<<grid[i][j]<<" ";
        }
        outFile<<endl;
    }
    outFile.close();
}
void Grid::LoadPattern1(char fileName[]){
    ifstream inFile;
    inFile.open(fileName);

    if(inFile.fail()){
        cout<<"could not open file...."<<endl;
        exit(0);
    }
    int length;
    int width;
    inFile>>length;
    inFile>>width;
    for(int i=cursorX; i<=cursorX+length; i++){
        for(int j=cursorY; j<=cursorY+width; j++){
             inFile>>grid[i][j];
        }


    }
    inFile.close();


}

void Grid::SetFirstY(int newY){
    firstY = newY;
}
void Grid::SetFirstX(int newX){
    firstX= newX;
}
int Grid::GetFirstX(){
    return firstX;
}
int Grid::GetFirstY(){
    return firstY;
}
void Grid::SetLastX(int newX){
    lastX = newX;
}
void Grid::SetLastY(int newY){
    lastY = newY;
}
int Grid::GetLastX(){
    return lastX;
}
int Grid::GetLastY(){
    return lastY;
}
void Grid::SetCursorX(int newX){
    cursorX = newX;
}
void Grid::SetCursorY(int newY){
    cursorY = newY;
}
int Grid::GetCursorX(){
    return cursorX;
}
int Grid::GetCursorY(){
    return cursorY;
}
