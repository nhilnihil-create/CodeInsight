#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    ll n;
    cin >> n;

    string S1, S2;
    cin >> S1 >> S2;

    int mode = -1;
    vector<ll> dp(n);
    if (S1[0] == S2[0]) {
        mode = 0;
        dp[0] = 3;
    }
    else {
        mode = 1;
        dp[0] = 6;
    }

    ll mod = 7LL + 1e9;
    repi(i, n) {
        if (mode == 1) {
            mode = 2;
            dp[i] = dp[i-1] % mod;
        }
        else {
            ll prev = mode;

            if (S1[i] == S2[i]) {
                mode = 0;
                if (prev == 0) {
                    dp[i] = dp[i-1] * 2 % mod;
                }
                else {
                    dp[i] = dp[i-1] % mod;
                }
            }
            else {
                mode = 1;
                if (prev == 0) {
                    dp[i] = dp[i-1] * 2 % mod;
                }
                else {
                    dp[i] = dp[i-1] * 3 % mod;
                }
            }
        }
    }

    put(dp[n-1]);
}
signed main(){ Main();return 0;}