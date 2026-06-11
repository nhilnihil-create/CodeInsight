#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

vector<vector<ll>> solve(int H, int W, int h, int w) {
    vector<ll> sum(W + 1), ret(W);
    sum[W] = 1;
    for(int i = W - w; i >= 0; i -= w)
        sum[i] = sum[i + w] + 1;
    rep(i, W - w) if(W % w != i % w) sum[i + w] = sum[i] - 1;

    rep(i, W) ret[i] = sum[i + 1] - sum[i];
    return vector<vector<ll>>(H, ret);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int H, W, h, w;
    cin >> H >> W >> h >> w;

    if(H % h == 0 && W % w == 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    bool rev = (W % w == 0);
    if(rev) {
        swap(H, W);
        swap(h, w);
    }
    vector<vector<ll>> ret = solve(H, W, h, w);

    if(rev) {
        rep(j, W) {
            rep(i, H) cout << ret[i][j] << " ";
            cout << endl;
        }
    } else {
        rep(i, H) {
            rep(j, W) cout << ret[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}