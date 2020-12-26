#ifndef RANDOM_H
#define RANDOM_H



class Random
{
public:
    Random();
    int GetNext(int lo,int hi);
private:
    static int objectCount;
};
#endif // RANDOM_H
