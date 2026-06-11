#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<math.h>
#include<utility>
using namespace std;


int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<char> > c(h, vector<char>(w));
    vector<vector<char> > res(2*h, vector<char>(w));
    for(int row=0;row<h;row++){
        for(int col=0;col<w;col++){
            cin >> c[row][col];
        }
    }

    for(int row=0;row<2*h;row++){
        for(int col=0;col<w;col++){
            res[row][col] = c[row/2][col];
            cout << res[row][col];
        }
        cout << endl;
    }
}