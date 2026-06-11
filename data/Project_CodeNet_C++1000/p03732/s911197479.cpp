#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
 
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
 
const ll oo = 1e15 + 7;
const int mod = 1e9 + 7, maxn = (2 * 1e3) + 10;
const long double PI = acos(-1);

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll N, W;

    cin >> N >> W;

    vector<vector<ll>> dp(N+1, vector<ll>(3*N + 1, -oo));
    vector<ll> w(N), v(N);

    dp[0][0] = 0;

    for (int i=0; i<N; i++){
        cin >> w[i] >> v[i];
    }

    ll base = w[0];

    for (int i=0; i<N; i++){
        ll sobra = w[i] - base;
        for (int j=N; j>=1; j--){
            for (int k=N*3; k>=sobra; k--){
                if (dp[j-1][k-sobra] != -oo){
                    dp[j][k] = max(dp[j-1][k-sobra] + v[i], dp[j][k]);
                }
            }
        }
    }
    ll ans = 0;

    for (int i=0; i<=N; i++){
        for (int j=0; j<=N*3; j++){
            if (i*base + j > W) break;
            ans = max(dp[i][j], ans);
        }
    }

    cout << ans << endl;

    return 0;
}