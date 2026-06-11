#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<vector<ll>> d(n+1, vector<ll>(n+1));
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            ll a;
            cin >> a;
            d[i][j] = a;
            ans += a;
        }
    }
    vector<vector<ll>> rec(n+1, vector<ll>(n+1));
    ll del = 0;
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(d[i][j] > d[i][k] + d[k][j])
                {
                    cout << -1 << endl;
                    return 0;
                }
                else if(d[i][j] == d[i][k] + d[k][j] && i!=k && k!=j && rec[i][j] == false) 
                {
                    del += d[i][j];
                    rec[i][j] = true;
                }
            }
        }
    }
    cout << (ans - del) / 2 << endl;
}

