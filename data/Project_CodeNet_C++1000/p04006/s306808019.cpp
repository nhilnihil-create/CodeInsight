#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int INF = 1e9+10;
int main()
{
    ll n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    reverse(a.begin(), a.end());
    vector<vector<int>> d(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
    {
        int v = INF;
        for(int j = 0; j < n; j++)
        {
            v = min(v, a[(i+j) % n]);
            d[i][j] = v;
        }
    }
    ll ans = 1e15;
    for(int cnt = 0; cnt < n; cnt++)
    {
        ll tmp = x * cnt;
        for(int i = 0; i < n; i++)
        {
            tmp += d[i][cnt];
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}
