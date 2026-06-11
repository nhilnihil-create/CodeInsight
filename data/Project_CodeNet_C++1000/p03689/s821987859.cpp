#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(unique(all(x)), x.end());
typedef long long ll;
typedef complex<double> Complex;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    for (int i = 0; i < sz(v); i++) {
        os << v[i];
        if (i < sz(v) - 1) os << " ";
    }
    return os;
}
int main() {
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    if (H % h == 0 && W % w == 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    if (W % w > 0) {
        int x = W / w + 1;
        int y = -x - 1;
        auto ans = make_vec<int>(H, W);
        rep(i, H) rep(j, W) {
            if (i % h == 0 && j % w == 0) ans[i][j] = x;
            if (i % h == h - 1 && j % w == 0) ans[i][j] = x;
            if (i % h == 0 && j % w == w - 1) ans[i][j] = y;
            if (i % h == h - 1 && j % w == w - 1) ans[i][j] = y;
        }
        rep(i, H) cout << ans[i] << endl;
    } else {
        int x = H / h + 1;
        int y = -x - 1;
        auto ans = make_vec<int>(H, W);
        rep(i, H) rep(j, W) {
            if (i % h == 0 && j % w == 0) ans[i][j] = x;
            if (i % h == h - 1 && j % w == 0) ans[i][j] = y;
            if (i % h == 0 && j % w == w - 1) ans[i][j] = x;
            if (i % h == h - 1 && j % w == w - 1) ans[i][j] = y;
        }
        rep(i, H) cout << ans[i] << endl;
    }
}