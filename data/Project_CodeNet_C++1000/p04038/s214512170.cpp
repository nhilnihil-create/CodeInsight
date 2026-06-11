#include<bits/stdc++.h>

using namespace std;
#define taskname "A"
#define pb  push_back
#define mp  make_pair
#ifndef LOCAL
#define cerr if(0)cout
#endif

typedef long double ld;
typedef long long ll;
typedef pair<int,int> ii;
const int maxn = 2e3 + 5;
const int maxm = maxn * maxn;
const int mod = 1e9 + 7;
int n , k , dp[maxn][maxn];
int f[maxm] , rf[maxm];
int C(int n , int k){
    if(k < 0 || n < 0 || k > n)return 0;
    return (ll)f[n] * rf[n - k] % mod * rf[k] % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
        freopen(taskname".INP", "r",stdin);
        freopen(taskname".OUT", "w",stdout);
    }
    cin >> n >> k;
    dp[0][0] = 1;
    f[0] = f[1] = rf[0] = rf[1] = 1;
    if(k == 1)return cout << 1 , 0;
    for(int i = 2 ; i < maxm ; ++i){
        f[i] = (ll)f[i - 1] * i % mod;
        rf[i] = (mod - (ll)(mod / i) * rf[mod % i] % mod);
    }
    for(int i = 2 ; i < maxm ; ++i)rf[i] = (ll)rf[i - 1] * rf[i] % mod;
    for(int i = 0 ; i <= n ; ++i){
        for(int j = 0 ; j <= n ; ++j){
            if(i == 0 && j == 0)continue;
            if(i > j)continue;
            if(i > 0)dp[i][j] = dp[i - 1][j];
            if(j > 0)dp[i][j] += (ll)dp[i][j - 1] * C(i + j * (k - 1) - 1 , k - 2) % mod;
            if(dp[i][j] >= mod)dp[i][j] -= mod;
//            cout << i << " " << j << " " << dp[i][j] << " " <<
//            i + j * (k - 1) - 1 << " " << k - 2 << " "  << C(i + j * (k - 1) - 1 , k - 2) <<endl;
        }
    }
    cout << ((ll)dp[n][n] * f[n]) % mod;
}
