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
    for (int i = -1; i <= 30; i++)
    {
        int mask;
        if (i == -1)
        {
            mask = k;
        }
        else
        {
            if (!(k >> i & 1))
                continue;
            mask = (k ^ (1 << i)) | ((1 << i) - 1);
        }
        long res = 0;
        for (int j = 0; j < n; j++)
        {
            if ((mask | as[j]) == mask)
            {
                res += bs[j];
            }
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
