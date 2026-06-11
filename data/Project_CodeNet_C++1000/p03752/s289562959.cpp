#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using piii = pair<int, pair<int, int>>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    ll ans = LLONG_MAX;
    for (int i = 0; i < (1 << N); ++i) {
        ll cost = 0;
        int cnt = 0;
        int maxh = 0;
        for (int j = 0; j < N; ++j) {
            if (i & (1 << j)) {
                cnt++;
                cost += max(maxh + 1 - a[j], 0);
                maxh = max(maxh + 1, a[j]);
            } else
                maxh = max(maxh, a[j]);
        }
        if (cnt >= K)
            ans = min(ans, cost);
    }

    cout << ans << endl;
    return 0;
}
