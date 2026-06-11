#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <cmath>
#include <cassert>
#include <string>
#include <iostream>
#include <bitset>
#include <numeric>

using namespace std;
typedef long long ll;
ll MOD = 1000000007;
ll ai[100010], ti[100010];
int main()
{
    int n;
    cin >> n;
    ll t[n], a[n];
    for (int i = 0; i < n; i++)
        cin >> t[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (t[n - 1] != a[0])
    {
        cout << 0 << endl;
        return 0;
    }

    ti[0] = t[0];
    for (int i = 0; i < n - 1; i++)
    {
        if (t[i] == t[i + 1])
        {
            ti[i + 1] = 0;
        }
        else
        {
            ti[i + 1] = t[i + 1];
        }
    }

    ai[n - 1] = a[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        if (a[i] == a[i - 1])
        {
            ai[i - 1] = 0;
        }
        else
        {
            ai[i - 1] = a[i - 1];
        }
    }

    ll ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (ti[i] == 0 || ai[i] == 0)//山の高さが確定
        {
            if ((ti[i] == 0 && ai[i] == 0))
            {
                ans = (ans * min(t[i], a[i])) % MOD;
            }
            else
            {
                if (ti[i] == 0)
                    ti[i] = ai[i];
                else
                    ai[i] = ti[i];
            }
        }
        else if (ti[i] != ai[i]) //山の高さが確定していて、等しくない時
        {
            cout << 0 << endl;
            return 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (ti[i] == 0 && ai[i] == 0)
        {
            continue;
        }
        if (ti[i] > t[i] || ai[i] > a[i])//確定した山の高さが、記録した最大値より大きい時
        {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << ans % MOD << endl;

}