#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans += a[i];
    }
    vector<vector<ll>> mi(n+1, vector<ll>(n+1));
    for(int i = 0; i < n; i++)
    {
        mi[i][0] = a[i];
        for(int j = 0; j < n; j++)
        {
            if(i-j-1 >= 0)
            {
                mi[i][j+1] = min(mi[i][j], a[i-j-1]);
            }
            else
            {
                mi[i][j+1] = min(mi[i][j], a[n+(i-j-1)]);
            }
        }
    }
    for(int num = 1; num < n; num++)
    {
        ll tmp = 0;
        for(int i = 0; i < n; i++)
        {
            tmp += mi[i][num];
        }
        tmp += x * num;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}
