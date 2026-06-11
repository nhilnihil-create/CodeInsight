#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<char>> Aij(H,vector<char>(W));

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> Aij[i][j];
        }
    }

    for(int j=0; j<W+1; j++){
        cout << '#';
    }
    cout << '#' << endl;

    for(int i=0; i<H; i++){
        cout << '#';
        for(int j=0; j<W; j++){
            cout << Aij[i][j];
        }
        cout << '#' << endl;
    }

    for(int j=0; j<W+1; j++){
        cout << '#';
    }
    cout << '#' << endl;

}