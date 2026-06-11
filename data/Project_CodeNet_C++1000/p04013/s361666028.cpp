#include <bits/stdc++.h>
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
void Main()
{
    ll n, A;
    cin >> n >> A;

    vector<ll> x(n);
    rep(i, n) cin >> x[i];
    
    vector<vector<vector<ll> > > dp(
        n + 1,
        vector<vector<ll> >(n + 1, vector<ll>(n * 50 + 1))
    );


    rep(j, n + 1) {
        dp[j][0][0] = 1;
    }
    repi(j, n + 1) {
        repi(k, n + 1) {
            repi (s, n * 50 + 1) {
                if (j == 4 && k == 2 && s == 8) {
 //                   put("A");
                }

                if (s - x[j - 1] >= 0) {
                    dp[j][k][s] = dp[j-1][k][s] + dp[j-1][k-1][s - x[j - 1]];
                }
                else {
                    dp[j][k][s] = dp[j-1][k][s];
                }
            }
        }
    }

    // int cnt = 0;
    // for (ll i = 0; i < n - 2; i++) {
    //     for (ll j = i + 1; j < n - 1; j++) {
    //         for (ll k = j + 1; k < n; k++) {
    //             if (x[i] + x[j] + x[k] == 15) {
    //                 cout << i << " " << j << " " << k << endl;
    //                 cnt++;
    //             }
    //         }
    //     }
    // }
 //   cout << "TOTAL " << cnt << endl;

    ll sum = 0;
    repi(k, n + 1) {
        sum += dp[n][k][k * A];
    }

    put(sum);
}
signed main(){ Main();return 0;}