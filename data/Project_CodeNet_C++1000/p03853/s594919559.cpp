#include<iostream>
using namespace std;

int main () {
    int H,W;
    cin >> H >> W;
    char mat[H][W];
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> mat[i][j];
        }
    }

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cout << mat[i][j];
        }
        cout << '\n';
        for(int j=0; j<W; j++){
            cout << mat[i][j];
        }
        cout << '\n';
    }
}

