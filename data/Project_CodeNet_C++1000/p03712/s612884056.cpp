#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> a(H, vector<char>(W));
    rep(i,H) rep(j,W) cin >> a.at(i).at(j);
    rep(i,H+2) rep(j,W+2) {
        if (i == 0 || i == H + 1 || j == 0 || j == W + 1) {
            cout << '#';
        } else cout << a.at(i-1).at(j-1);
        if (j == W + 1) cout << endl;
    }
}
