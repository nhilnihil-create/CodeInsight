#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;
using ll = long long;
int main()
{
    ll a[3];
    cin >> a[0] >> a[1] >> a[2];
    for (int i = 0; i < 3; ++i)
    {
        if (a[i] & 1)
        {
            cout << 0 << endl;
            return 0;
        }
    }
    if (a[0] == a[1] && a[1] == a[2])
    {
        cout << -1 << endl;
        return 0;
    }

    ll ans = 0, q[3];
    bool gok = true;
    while(1)
    {
        for (int i = 0; i < 3; ++i)
        {
            q[i] = a[i] / 2;
        }
        for (int i = 0; i < 3; ++i)
        {
            a[i] = q[(i + 1) % 3] + q[(i + 2) % 3];
        }
        ++ans;
        if (a[0] & 1 || a[1] & 1 || a[2] & 1) break;
    }
    cout << ans << endl;
    return 0;
}
