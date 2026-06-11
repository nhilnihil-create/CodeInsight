#include "bits/stdc++.h"

using namespace std;

void solve()
{
    long n, a, b;
    cin >> n >> a >> b;
    vector<long> hs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> hs[i];
    }
    long c = a - b;
    long ng = 0, ok = 1e9;
    while (ng + 1 < ok)
    {
        long m = (ok + ng) >> 1;
        vector<long> rs;
        long k = 0;
        for (int i = 0; i < n; i++)
        {
            long h = hs[i] - b * m;
            k += max(0L, (h + c - 1) / c);
        }
        (k <= m ? ok : ng) = m;
    }
    cout << ok << endl;
}

int main()
{
    solve();
    return 0;
}
