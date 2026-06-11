 #pragma GCC optimize("O3")
 #pragma GCC optimize("unroll-loops")
 #pragma GCC optimize("fast-math")
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define int long long
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

void accell() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
}
const int N = 1e5 + 5;

int dp[N][4];

signed main() {
    accell();
    int n, x;
    cin >> n >> x;
    vector<int>a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int>ans(n, 1e18);
    int ass = 1e18;
    for (int k = 1; k <= n; ++k) {
        for (int j = 0; j < n; ++j) {
            int p = (j - k + 1 + n) % n;
            ans[j] = min(ans[j], a[p]);
        }
        int res = 0;
        for (int j = 0; j < n; ++j)
            res += ans[j];
        ass = min(ass, res + (k - 1) * x);
    }
    cout << ass << '\n';
    return 0;
}
