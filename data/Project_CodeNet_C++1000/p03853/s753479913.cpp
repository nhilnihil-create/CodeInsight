#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char> > pic(H,vector<char>(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> pic.at(i).at(j);
        }
    }
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cout << pic.at(i).at(j);
        }
        cout << endl;
        for(int j = 0; j < W; j++) {
            cout << pic.at(i).at(j);
        }
        cout << endl;
    }
    


    return 0;
}