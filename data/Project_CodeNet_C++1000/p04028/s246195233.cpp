#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
const int maxn = 5000 + 5;
const int mod = 1e9 + 7;
string a;
int dp[maxn][maxn];
ll ksm (ll a , ll b)
{
    ll ans = 1 , base = a;
    while (b){
        if (b & 1) ans = ans * base % mod;
        b >>= 1;
        base = base * base % mod;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    int n; cin >> n;
    cin >> a; int m = a.size();
    dp[0][0] = 1;
    for (int i = 0 ; i <= n ; i++){
        for (int j = 0 ; j <= n ; j++){
            dp[i + 1][j + 1] = (dp[i + 1][j + 1] + 2 * dp[i][j]%mod)%mod;
            dp[i + 1][max(0,j - 1)] = (dp[i + 1][max(0,j - 1)] + dp[i][j]) % mod;
        }
    }
  //  cout << dp[n][m] << endl;
    ll res = ksm(ksm(2 , m) , mod - 2);
    ll ans = dp[n][m] * res % mod;
    cout << ans << endl;
    return 0;
}

/*
2 3
1 2
1 2
*/
