#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
 
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
 
const ll oo = 1e11 + 7;
const int mod = 1e9 + 7, maxn = 1000010;
const long double PI = acos(-1);


int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, W, base;
    cin >> n >> W;

    vector<vector<ll>> dp(n+1, vector<ll> ((n+1)*4, -1));
    vector<ll> v(n), w(n);

    for (int i=0; i<n; i++){
        cin >> w[i] >> v[i];
    }
    base = w[0];
    dp[0][0] = 0;

    for (int i=0; i<n; i++){
        ll sobra = w[i] - base;

        for (int j=n; j>=1; j--){
            for (int k=n*4; k>=sobra; k--){
                if (dp[j-1][k-sobra] != -1){
                    dp[j][k] = max(dp[j-1][k-sobra] + v[i], dp[j][k]);
                }
            }
        }
    }

    ll ans = 0;

    for (int i=0; i<=n; i++){
        for (int j=0; j<=n*4; j++){
            if (i*base + j > W) break;
            ans = max(dp[i][j], ans);
        }
    }

    cout << ans << endl;

    return 0;
}