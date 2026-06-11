#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 1e12;
    for(int i = 0; i < 1<<n; i++)
    {
        int count = __builtin_popcount(i);
        if(count != k) continue;
        ll cost = 0;
        int h = 0;
        for(int j = 0; j < n; j++)
        {
            if(i >> j & 1)
            {
                if(a[j] <= h)
                {
                    cost += h - a[j] + 1;
                    h++;
                }
                else
                {
                    h = a[j];
                }
            }
            else h = max(h, a[j]);
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;
}

