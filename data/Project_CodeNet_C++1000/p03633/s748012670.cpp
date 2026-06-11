#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];

    ll ans = t[0];
    for (int i = 1; i < n; i++)
    {
        ans = lcm(ans, t[i]);
    }

    cout << ans << endl;
    return 0;
}