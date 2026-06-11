#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;

    vector<vector<char>> image(H,vector<char>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> image.at(i).at(j);
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << image.at(i).at(j);
        }
        cout << endl;
        for(int k = 0; k < W; k++){
            cout << image.at(i).at(k);
        }
        cout << endl;
    }
}