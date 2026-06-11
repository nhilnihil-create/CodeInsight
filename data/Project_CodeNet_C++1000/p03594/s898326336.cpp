#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
constexpr ll INF = (1LL << 30) - 1LL;
constexpr ll LINF = (1LL << 60) - 1LL;
constexpr ll MOD = 1e9 + 7;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
int c[1010][1010];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w, d;
    cin >> h >> w >> d;
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            for (int k = 0; k * d + i <= 1000; k++) {
                for (int l = 0; l * d + j <= 1000; l++) {
                    if (k % 2 == 0) {
                        if (l % 2 == 0) {
                            c[k * d + i][l * d + j] = 0;
                        } else {
                            c[k * d + i][l * d + j] = 1;
                        }
                    } else {
                        if (l % 2 == 0) {
                            c[k * d + i][l * d + j] = 2;
                        } else {
                            c[k * d + i][l * d + j] = 3;
                        }
                    }
                }
            }
        }
    }
    string s = "RYGB";
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << s[c[i + j][i - j + 500]];
        }
        cout << "\n";
    }
}