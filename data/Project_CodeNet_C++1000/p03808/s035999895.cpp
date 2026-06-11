#include <bits/stdc++.h>
using namespace std;
int main()
{
    using ll = long long;
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    ll x = n * (n+1) / 2;
    if(sum % x != 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    ll y = sum / x;
    for(int i = 0; i < n; i++)
    {   ll cand = 0;
        cand = a[i+1] - a[i];
        if(i == n-1)
        {
          cand = a[0]-a[i];
        }
        cand -= y;
        if(cand % n != 0 || cand > 0)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}

