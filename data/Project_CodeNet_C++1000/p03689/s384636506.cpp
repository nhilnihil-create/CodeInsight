// Template
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <tuple>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <cmath>
#define rep(i, x) for (int i = 0; i < (x); ++i)
#define rng(i, x, y) for (int i = (x); i < (y); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003;
template <typename T> inline bool chmin(T &x, const T &y) {if (x > y) {x = y; return 1;} return 0;}
template <typename T> inline bool chmax(T &x, const T &y) {if (x < y) {x = y; return 1;} return 0;}

// Main Code
int main() {
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    
    if (H % h == 0 && W % w == 0) {
        cout << "No\n";
        return 0;
    }
    
    vector<vector<ll>> a(H, vector<ll>(W, 0));
    ll sum = 0;
    rep(i, H) rep(j, W) {
        if (i % h == h - 1 && j % w == w - 1) a[i][j] = -h * w;
        else a[i][j] = 1;
        sum += a[i][j];
    }
    
    if (sum <= 0) {
        if (H % h == 0) {
            ll x = (-sum + (W % w) - 1) / (W % w) + 1;
            rep(i, W) a[H - 1][i] += x;
            rep(i, W / w) a[H / h * h - 1][(i + 1) * w - 1] -= w * x;
        } else {
            ll x = (-sum + (H % h) - 1) / (H % h) + 1;
            rep(i, H) a[i][W - 1] += x;
            rep(i, H / h) a[(i + 1) * h - 1][W / w * w - 1] -= h * x;
        }
    }
    
    cout << "Yes\n";
    rep(i, H) rep(j, W) cout << a[i][j] << " \n"[j == W - 1];
    return 0;
}
