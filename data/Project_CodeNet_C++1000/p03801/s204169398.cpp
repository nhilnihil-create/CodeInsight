#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define rep(i, a, n) for (ll i = a; i < (ll)(n); i++)


signed main()
{
    int n;
    cin >> n;
    vector<ll> v(n), u(n, 0);
    rep(i, 0, n)
    {
        cin >> v[i];
        u[i] = v[i];
    }
    sort(all(u));

    ll ind = 0, mx = 0;
    rep(i, 0, n)
    {
        if (v[i] <= mx)
        {
            cout << 0 << endl;
        }
        else
        {
            ll sum=0;
            while (ind<n && u[ind] < v[i])
            {
                sum+=u[ind]-mx;
                ind++;
            }
            sum+=(n-ind)*(v[i]-mx);
            cout<<sum<<endl;
            mx=v[i];
        }
    }
}