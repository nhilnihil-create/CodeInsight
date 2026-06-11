#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> c(h, vector<char>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> c.at(i).at(j);

    for (int i = 0, n = 2 * h; i < n; i++) {
        for (int j = 0; j < w; j++)
            cout << c.at(i / 2).at(j);

        cout << endl;
    }
}