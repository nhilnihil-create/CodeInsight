#include "bits/stdc++.h"

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> as(n), bs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> as[i] >> bs[i];
    }
    long ans = 0;
    for (int x = 0; x < n; x++)
    {
        bool f = 1;
        for (int i = 30; i >= 0; i--)
        {
            if ((k >> i & 1) < (as[x] >> i & 1))
                f = 0;
        }
        if (f)
            ans += bs[x];
    }
    for (int i = 30; i >= 0; i--)
    {
        if (!(k >> i & 1))
            continue;
        long res = 0;
        for (int x = 0; x < n; x++)
        {
            if (as[x] >> i & 1)
                continue;
            bool f = 1;
            for (int j = 30; j > i; j--)
            {
                if ((k >> j & 1) < (as[x] >> j & 1))
                    f = 0;
            }
            if (f)
                res += bs[x];
            //cout << i << ' ' << as[x] << ' ' << f << endl;
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}
