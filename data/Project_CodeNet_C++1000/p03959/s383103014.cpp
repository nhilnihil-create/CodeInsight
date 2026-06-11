#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

template<typename T> 
void print(vector<T> &x) {
    int n = x.size();
    REP(i,n) {
        if (i != n-1) cout << x[i] << " ";
        else cout << x[i] << endl;
    }
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<ll> t(n+2,0), a(n+2,0), dp(n+2, -1);
    for (int i = 1; i <= n; ++i) cin >> t[i];
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (n == 1) {
        if (t[1] != a[1]) {
            cout << 0 << endl;
            return 0;
        }
    }

    for (int i = 0; i <= n; ++i) {
        if (t[i] != t[i+1]) {
            if (t[i+1] <= a[i+1]) {
                dp[i+1] = 1;
            }
            else dp[i+1] = 0;
        }
    }

    // print(dp);
    for (int i = n+1; i >= 2; --i) {
        if (a[i] != a[i-1]) {
            if (a[i-1] <= t[i-1]) {
                dp[i-1] = 1;
            }
            else dp[i-1] = 0;
        }
    }

    // print(dp);
    for (int i = 1; i <= n; ++i) {
        if (dp[i] == -1) {
            dp[i] = min(a[i],t[i]);
        }
    }

    // print(dp);
    ll ans = 1ll;
    for (int i = 1; i <= n; ++i) {
        ans *= dp[i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}