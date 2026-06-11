#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long h, w;
    cin >> h >> w;
    char c[h][w];
    char c2[2*h][w];

    for(long long y = 0; y < h; y++){
        for(long long x = 0; x < w; x++){
            cin >> c[y][x];
        }
    }

    for(long long y = 0; y < 2*h; y++){
        for(long long x = 0; x < w; x++){
            c2[y][x] = c[y/2][x];
        }
    }


    for(long long y = 0; y < 2*h; y++){
        for(long long x = 0; x < w; x++){
            printf("%c", c2[y][x]);
        }
        printf("\n");
    }
    return 0;
}