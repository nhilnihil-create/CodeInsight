#include "bits/stdc++.h"

using namespace std;

void Main() {
    int H, W;
    cin >> H >> W;
    vector<vector<string> > C(H, vector<string>(W, ""));
    for (int i = 0; i < H; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < W; ++j) {
            C[i][j] = s.substr(j, 1);
        }
    }

    for (int i = 0; i < 2 * H; ++i) {
        for (int j = 0; j < W; ++j) {
            cout << C[i / 2][j];
        }
        cout << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
