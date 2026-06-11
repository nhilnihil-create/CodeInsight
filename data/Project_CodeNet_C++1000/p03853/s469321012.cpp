#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> table(h, vector<char>(w));
    rep(i, h) rep(j, w) cin >> table[i][j];

    vector<vector<char>> table2(h*2, vector<char>(w));
    rep(i, h*2) rep(j, w) {
        table2[i][j] = table[i/2][j];
    }

    rep(i, h*2) rep(j, w) {
        cout << table2[i][j];
        if (j == w-1) cout << endl;
    }
}