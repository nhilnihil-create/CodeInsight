/*
#include <bits/stdc++.h>
//*/
//*
#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <cmath>
//*/
#define REP(i,n) for(ll i=0;i<(n);i++)
#define MOD 1000000007
#define int long long
#ifdef int
    const long long INF = LLONG_MAX / 10;
#else
    const int INF = 1010101010;
#endif
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> mat;
typedef pair<int, int> P;
//typedef pair<double, double> P;

int H, W, d;
char grid[2020][2020];
char ansGrid[3000][3000];

signed main()
{
    cin >> H >> W >> d;
    for (int y=0; y<2020; y++) {
        for (int x=0; x<2020; x++) {
            if ((y / d) % 2 == 0) {
                if ((x / d) % 2 == 0) grid[y][x] = 'R';
                else grid[y][x] = 'Y';
            } else {
                if ((x / d) % 2 == 0) grid[y][x] = 'G';
                else grid[y][x] = 'B';
            }
        }
    }

    /*
    REP(i,10) {
        REP(j,10) {
            cout << grid[i][j];
        }
        cout << endl;
    }*/

    REP(y,2020) {
        REP(x,2020) {
            int X = (x + y) / 2;
            int Y = (x - y) / 2;
            if (0 < X && X < 3000 && 0 < Y && Y < 3000) {
                ansGrid[X][Y] =grid[x][y];
            }
        }
    }

    for (int y=W; y<W+H; y++) {
        for (int x=1; x<=W; x++) {
            cout << ansGrid[y][x];
        }
        cout << endl;
    }

/*
    REP(i,10) {
        REP(j,10) {
            cout << ansGrid[i][j];
        }
        cout << endl;
    }
    */
}
