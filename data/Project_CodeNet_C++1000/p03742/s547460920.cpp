#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long x,y;
    scanf("%ld %ld", &x, &y);
    if(abs(x-y) < 2){
        printf("Brown");
    } else {
        printf("Alice");
    }
    
    return 0;
}
