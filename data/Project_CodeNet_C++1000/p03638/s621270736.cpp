#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;

    int n;
    cin >> n;

    vi a(n);
    rep(i, n) cin >> a[i];

    vector<int> v(h * w);

    int idx = 0;
    rep(i, n) {
        rep(j, a[i]) {
            v[idx] = i + 1;
            idx++;
        }
    }

    vector<vector<int>> ans(h, vector<int>(w));

    bool rev = true;
    rep(i, h) {
        rep(j, w) {
            int idx = i * w + j;

            if (rev) {
                ans[i][j] = v[idx];
            } else {
                ans[i][w - j - 1] = v[idx];
            }

            if (j == w - 1) {
                rev = !rev;
            }
        }
    }

    rep(i, h) {
        rep(j, w) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}