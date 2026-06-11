#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

int main() {
    int H, W; cin >> H >> W;
    vector<vector<char>> data(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> data.at(i).at(j);
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << data.at(i).at(j);
        }
        cout << endl;
        for (int j = 0; j < W; j++) {
            cout << data.at(i).at(j);
        }
        cout << endl;
    }
}