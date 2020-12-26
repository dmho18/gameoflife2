#include "random.h"
#include <time.h>
#include<random>
int Random::objectCount=0;
Random::Random(){
    objectCount++;
    if(objectCount==1){
        srand(time(0));
    }
}
int Random::GetNext(int lo, int hi){
    int r=rand()%(hi-lo+1)+lo;
    return r;
}
