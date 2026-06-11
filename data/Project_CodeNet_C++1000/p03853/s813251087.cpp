#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <cctype>
#include <map>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define FOR(i,l,r) for(size_t i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)



using namespace std;

bool is_integer( float x ){
    return floor(x)==x;
}


int main() {
    char ch[101][101];

    int h,w;
    cin >> h >> w;

    for(int i = 0; i < h; i ++){
        for(int j = 0; j < w; j ++){
            cin >> ch[i][j];
        }
    }

    for(int i = 0; i < h; i ++){
        for(int k = 0; k < 2; k ++) {
            for (int j = 0; j < w; j++) {
                cout << ch[i][j];
            }
            cout << endl;
        }
    }


    return 0;
}









