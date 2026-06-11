#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define inf 1000000100

int dp[41][403][403];

int main()
{
    int n, ma, mb;
    cin >> n >> ma >> mb;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j < 403; j++)
        {
            for(int k = 0; k < 403; k++)
            {
                dp[i][j][k] = 5000;
            }
        }
    }
    vector<tuple<int, int, int>> chemical;

    for(int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        chemical.pb(make_tuple(a, b, c));
    }

    dp[1][0][0] = 0;
    dp[1][get<0>(chemical[0])][get<1>(chemical[0])] = get<2>(chemical[0]);
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < 403; j++)
        {
            for(int k = 0; k < 403; k++)
            {
                if(dp[i][j][k] == 5000) continue;
                dp[i+1][j][k] = min(dp[i][j][k], dp[i+1][j][k]);
                dp[i+1][j+get<0>(chemical[i])][k+get<1>(chemical[i])] = min(dp[i+1][j+get<0>(chemical[i])][k+get<1>(chemical[i])], dp[i][j][k] + get<2>(chemical[i]));
            }
        }
    }

    int ans = inf;
    for(int j = 1; j < 403; j++)
    {
        for(int k = 1; k < 403; k++)
        {
            if(j*mb == k*ma)
            {
                ans = min(ans, dp[n][j][k]);
            }
        }
    }
    if(ans == 5000)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }

}