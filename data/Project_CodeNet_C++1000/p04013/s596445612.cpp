#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define endl "\n"

const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int N = 55;

ll n, k, a[N], dp[N][N * N][N];

ll solve(int i, int sum, int cnt) {
    if (i == n) 
        return cnt && sum % cnt == 0 && 
            sum / cnt == k ? 1 : 0;
    ll& ret = dp[i][sum][cnt];
    if (~ret)
        return ret;
    ret = solve(i + 1, sum, cnt) + 
        solve(i + 1, sum + a[i], cnt + 1);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    memset(dp, -1, sizeof(dp));

    cout << solve(0, 0, 0) << endl;
}
