#ifndef GRID_H
#define GRID_H
#include <iostream>;
const int MAX=60;
class Grid
{
public:
    Grid();
    void Init();
    void Print();
    bool IsAlive(int i, int j);
    int CountNeigbors(int i, int j);
    void Step();
    void SetAlive(int i, int j);
    void Kill(int i, int j);
    void Clear();
    void PopulateRandom(int n);
    void Save(char fileName[]);
    void Load(char fileName[]);
    int getAtCoords(int i, int j);
    void SavePattern1(char fileName[]);
    void LoadPattern1(char fileName[]);
    void SetFirstX(int newX);
    void SetFirstY(int newY);
    void SetLastX(int newX);
    void SetLastY(int newY);
    void SetCursorX(int newX);
    void SetCursorY(int newY);

    int GetFirstX();
    int GetFirstY();
    int GetLastX();
    int GetLastY();
    int GetCursorX();
    int GetCursorY();

private:
    int grid[MAX][MAX];
    int firstX;
    int firstY;
    int lastX;
    int lastY;
    int cursorX;
    int cursorY;
};



#endif // GRID_H
