#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
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

    int N, Ma, Mb;
    cin >> N >> Ma >> Mb;
    vector<vector<int>> dp(405, vector<int>(405, 1e9));
    dp[0][0] = 0;
    for (int i = 0; i < N; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = 400; j >= a; --j)
            for (int k = 400; k >= b; --k)
                dp[j][k] = min(dp[j][k], dp[j - a][k - b] + c);
    }

    int ans = 1e9;
    for (int i = 1; i * max(Ma, Mb) <= 400; ++i)
        ans = min(ans, dp[i * Ma][i * Mb]);

    cout << (ans < 1e9 ? ans : -1) << endl;
    return 0;
}
