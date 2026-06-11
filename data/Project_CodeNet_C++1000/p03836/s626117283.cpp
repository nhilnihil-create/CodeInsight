#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    for(long long i = 0; i < ty-sy; i++){
        printf("U");
    }
    for(long long i = 0; i < tx-sx; i++){
        printf("R");
    }
    for(long long i = 0; i < ty-sy; i++){
        printf("D");
    }
    for(long long i = 0; i < tx-sx+1; i++){
        printf("L");
    }
    for(long long i = 0; i < ty-sy+1; i++){
        printf("U");
    }
    for(long long i = 0; i < tx-sx+1; i++){
        printf("R");
    }
    printf("D");
    printf("R");
    for(long long i = 0; i < ty-sy+1; i++){
        printf("D");
    }
    for(long long i = 0; i < tx-sx+1; i++){
        printf("L");
    }
    printf("U\n");


    return 0;

}