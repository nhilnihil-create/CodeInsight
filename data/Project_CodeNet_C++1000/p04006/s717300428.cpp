#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, x;
    cin >> N >> x;
    vector<int> a(N);
    vector<vector<int>> mi(N, vector<int>(N, INT_MAX));
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        mi[i][i] = a[i];
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int l = j, r = j + i;
            if (r >= N)
                r -= N;

            if (r == 0)
                mi[l][r] = min(mi[l][N - 1], a[r]);
            else
                mi[l][r] = min(mi[l][r - 1], a[r]);
        }
    }

    ll ans = LLONG_MAX;
    for (int i = 0; i < N; ++i) {
        ll tmp = (ll)i * x;
        for (int j = 0; j < N; ++j) {
            int l = j - i, r = j;
            if (l < 0)
                l += N;
            tmp += mi[l][r];
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}
