#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        int sum = a[i] + a[i - 1];
        if (sum > x)
        {
            int sub = sum - x;
            ans += min(a[i], sub);
            int tmp = a[i];
            a[i] -= min(sub, a[i]);
            sub -= tmp;
            if (sub > 0)
            {
                ans += sub;
            }
        }
    }
    cout << ans << endl;
    return 0;
}