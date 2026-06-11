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
    ll n, K;
    cin >> n >> K;

    // n = 5000;
    // K = 5000;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    
    sort(all(a));

    // dp[i][j]: i個目まで使ったときの総和がjである場合
    vector<vector<char> > dp(n+1, vector<char>(K+1));
    dp[0][0] = 1;
    repi(i, n+1) {
        rep(j, K+1) {
            if (j-a[i-1] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-a[i-1]]); //use
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]); //unuse
        }
    }

    vector<vector<char> > dpi(n+2, vector<char>(K+1));
    dpi[n+1][0] = 1;
    for (int i = n; i >= 0; i--) {
        rep(j, K+1) {
            if (j-a[i-1] >= 0) {
                dpi[i][j] = max(dpi[i][j], dpi[i+1][j-a[i-1]]); //use
            }
            dpi[i][j] = max(dpi[i][j], dpi[i+1][j]); //unuse
        }
    }


    ll res = 0;
    vector<ll> S(K+2);
    rep(i, n) {
        repi(j, K+2) {
            S[j] = S[j-1] + dpi[i+2][j-1];
        }
        bool necessary = false;
        rep(j, K+1) {
            if (0 == dp[i][j]) {
                continue;
            }
            ll sum = i - 1 >= 0 ? j + a[i] : a[i];
            if (sum > K) {
                necessary = true;
                break;
            }
            ll v1 = K - sum;
            ll v2 = K + a[i] - 1 - sum;
            ll cnt = S[v2+1] - S[v1];
            if (cnt > 0) {
                necessary = true;
                break;
            }
        }
        if (!necessary) {
            res++;
        }
    }
    put(res);
}
signed main(){ Main();return 0;}