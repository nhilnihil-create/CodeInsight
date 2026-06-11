#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using Graph = vector<vector<int>>;
const int INF = 1e9 + 1;
const ll LLINF = 1e18;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, A;
    cin >> N >> A;

    vector<vector<ll>> dp(N * 50 + 3, vector<ll>(N + 3));
    dp[0][0] = 1;
    for (int i = 1; i <= N; ++i) {
        int x;
        cin >> x;
        for (int j = i; j > 0; --j)
            for (int k = j * 50; k >= x; --k)
                dp[k][j] += dp[k - x][j - 1];
    }
    ll ans = 0;
    for (int i = 1; i <= N; ++i)
        ans += dp[A * i][i];
    cout << ans << endl;

    return 0;
}
