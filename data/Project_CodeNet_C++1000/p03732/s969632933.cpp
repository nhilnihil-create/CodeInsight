#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(void)
{
    IOS
    int n, w;
    cin >> n >> w;
    vector<int> vv(n) , vw(n);
    REP(i,n) cin >> vw[i] >> vv[i];
    ll w1 = vw[0];
    int ans = 0;

    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(n*3)));

    REP(i,n) for(int j = i; j>=0;j--) for(int k = j*3;k >= 0;k--) {
        //cerr << "dp" << i << j << k << endl;
        if (w1 * j + k + vw[i] <= w) {
            //cerr << i << " " << j << " " << k + vw[i] - w1 << " " << w1 * j + k + vw[i] << " " << dp[i][j][k] + vv[i]<< endl;
            dp[i+1][j+1][k + vw[i] - w1] = max(dp[i+1][j+1][k + vw[i] - w1], dp[i][j][k] + vv[i]);
            ans = max(ans,dp[i+1][j+1][k + vw[i] - w1]);
        }
        //cerr << i << " "<< j << " " << k << " "<< dp[i][j][k] << endl;
        dp[i+1][j][k] = dp[i][j][k];
    }

    cout << ans << '\n';

    return 0;
}