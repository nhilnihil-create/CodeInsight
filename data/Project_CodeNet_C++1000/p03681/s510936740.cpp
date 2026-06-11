#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define MOD 1000000007

vector<ll> dp(100010, -1);


ll modfact (ll n) {
    if (dp[n] != -1) return dp[n];
    if (n == 0) return dp[0] = 1;
    else return dp[n] = n * modfact(n - 1) % MOD;
}


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n, m;
    scanf("%lld %lld", &n, &m);
    
    if (m < n - 1 || n + 1 < m) {
        printf("%d\n", 0);
        return 0;
    }

    ll ans;
    if (m == n) ans = modfact(n) * modfact(m) * 2 % MOD;
    else ans = modfact(n) * modfact(m) % MOD;

    printf("%lld\n", ans);
}