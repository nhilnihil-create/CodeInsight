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
    rep(i,H) rep(j,2) rep(k,W) {
        cout << a.at(i).at(k);
        if (k == W-1) cout << endl;
    }
}
