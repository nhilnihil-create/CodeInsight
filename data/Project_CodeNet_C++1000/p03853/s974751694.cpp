#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> C(H, vector<char>(W));
    rep(i, H) {
        rep(j, W) {
            cin >> C.at(i).at(j);
        }
    }

    rep(i, 2 * H) {
        rep(j, W) {
            int index = (i + 2) / 2 - 1;
            cout << C.at(index).at(j);
        }
        cout << endl;
    }

    return 0;
}