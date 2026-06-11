#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma optimize("JARU SOSISONI")

using namespace std;

#define int long long
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define geometry cout.setf(ios::fixed); cout.precision(15);
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;

const int INF = 1e9 + 100;
const int MOD = 998244353;
const int MOD1 = 1e9 + 7;
const int N = 52;
const int nul = 0;
const int SIZE = 1e6 * 3;

int n, x;

int sub(int i, int k) {
    if (i - k >= 0) return i - k;
    else return i - k + n;
}

vector<vector<int> > dp;
vector<int> a;

int check(int k) {
    for (int i = 0; i < n; i++) {
        dp[i][k] = min(dp[i][k - 1], a[sub(i, k)]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans += dp[i][k];
    return ans;
}

signed main() {
#ifdef parasha
    freopen("A.in", "r", stdin);
#endif // parasha
    fast;
    cin >> n >> x;
    a.resize(n);
    dp.resize(n, vector<int>(n, INF));
    for (int &i : a) cin >> i;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i][0] = a[i];
        ans += a[i];
    }
    for (int k = 1; k < n; k++) {
        ans = min(ans, k * x + check(k));
    }
    cout << ans << endl;

}
