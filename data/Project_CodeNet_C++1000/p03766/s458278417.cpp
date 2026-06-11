//In The Name of Allah
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 10;
const ll mod = 1e9 + 7;

ll dp[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    dp[0] = 1;
    dp[1] = n;
    ll ps = n - 1;
    for (ll i = 2; i <= n; i ++){
        dp[i] = (dp[i - 1] + (n - 1) * (n - 1) % mod + ps) % mod;
        ps = (ps + dp[i - 2] - 1) % mod;
    }
    dp[n] = (dp[n] + mod) % mod;
    cout << dp[n];
    return 0;
}
