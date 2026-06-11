#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
#include <cmath>
#include <limits.h>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <stdio.h>
using namespace std;

long long MOD = 1000000007;

int main() {
    
    char C[1000][1000];
    char color[2][2] = { {'R', 'Y'}, {'G', 'B'} };
    int H,W,D;
    cin >> H >> W >> D;
    
    
    for ( int i = 0; i < H+W; i++ ) {
    for ( int j = 0; j < H+W; j++ ) {        
        C[i][j] = color[ (i/D)%2 ][ (j/D)%2 ];
    }
    }
    
    for ( int i = 0; i < H; i++ ) {
        for ( int j = 0; j < W; j++ ) {        
            cout << C[i+j][i-j+W];
        }
        cout << endl;
    }
    
    
    
    
    
    return 0;
}