#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
ll dp[51][51][2501];
int main()
{
    int n,a;cin >> n >> a;
    vector<int> x(n);rep(i,n)cin >> x[i];
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <=i ; j++)
        {
            for (int k = 0; k  < 2500; k  ++)
            {
                if(k+x[i]<=2500)
                {
                    dp[i + 1][j + 1][k + x[i]] += dp[i][j][k];
                }
                dp[i + 1][j][k] += dp[i][j][k];
            }
            
        }   
    }
    ll ans = 0;
    for (int i = 1; i <=n; i++)
    {
        ans+= dp[n][i][i*a];
    }
    
    cout << ans << endl;
}