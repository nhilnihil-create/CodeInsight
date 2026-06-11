#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

void solve() {
    int H, W, h, w;
    cin >> H >> W >> h >> w;

    if (H % h == 0 && W % w == 0) {
        cout << "No" << '\n';
    } else if (H%h == 0) {
        cout << "Yes" << '\n';
        vector<int> s(W+1), a(W);
        for (int i=0; i<w; ++i) {
            int c = i;
            if (c == 0) s[c] = 0;
            else s[c] = 1000;
            c += w;
            while (c < W + 1) {
                s[c] = s[c-w] - 1;
                c += w;
            }
        }
        for (int i=0; i<W; ++i) a[i] = s[i+1] - s[i];
        for (int i=0; i<H; ++i) {
            for (int j=0; j<W; ++j) {
                cout << a[j];
                if (j == W-1) cout << '\n';
                else cout << ' ';
            }
        }
    } else {
        cout << "Yes" << '\n';
        vector<int> s(H+1), a(H);
        for (int i=0; i<h; ++i) {
            int c = i;
            if (c == 0) s[c] = 0;
            else s[c] = 1000;
            c += h;
            while (c < H + 1) {
                s[c] = s[c-h] - 1;
                c += h;
            }
        }
        for (int i=0; i<H; ++i) a[i] = s[i+1] - s[i];
        for (int i=0; i<H; ++i) {
            for (int j=0; j<W; ++j) {
                cout << a[i];
                if (j == W-1) cout << '\n';
                else cout << ' ';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
