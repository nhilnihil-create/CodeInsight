#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<int, int>;
 
template <typename T> T inf;
template <> constexpr int inf<int> = 1e9;
template <> constexpr ll inf<ll> = 1e18;

int main() {
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    int x = inf<int> / (h * w);
    vector<vector<int>> a(H, vector<int>(W, x));
    for(int i = h - 1; i < H; i += h) {
        for(int j = w - 1; j < W; j += w) {
            a[i][j] = -x * (h * w - 1) - 1;
        }
    }
    ll sum = 0;
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            sum += a[i][j];
        }
    }
    if(sum > 0) {
        cout << "Yes" << endl;
        for(int i = 0; i < H; ++i) {
            for(int j = 0; j < W; ++j) {
                cout << a[i][j] << " \n"[j + 1 == W];
            }
        }
    } else {
        cout << "No" << endl;
    }
}
