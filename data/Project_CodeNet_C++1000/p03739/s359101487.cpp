#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll ans = 1LL << 60LL;
    int cnt = 0;
    ll mod1 = 1;
    ll mod2 = 0;
    while (cnt < 2)
    {
        ll acc = 0;
        ll res = 0;

        for (int i = 0; i < n; i++)
        {
            acc += a[i];
            if (i % 2 == mod2 & acc >= 0)
            {
                res += abs(acc) + 1;
                acc = -1;
            }
            if (i % 2 == mod1 & acc <= 0)
            {
                res += abs(acc) + 1;
                acc = 1;
            }
        }
        ans = min(ans, res);
        swap(mod1, mod2);
        cnt++;
    }
    cout << ans << endl;
    return 0;
}