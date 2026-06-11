#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int main(){
    int h,w;
    cin >> h >> w;
    char C[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> C[i][j];
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<w;k++){
                cout << C[i][k];
            }
            cout << endl;
        }
    }
}