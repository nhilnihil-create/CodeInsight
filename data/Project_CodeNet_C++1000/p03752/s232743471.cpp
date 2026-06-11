#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n = 0, k = 0;
    cin >> n >> k;

    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll cmin = LLONG_MAX;
    for (int bit = 0; bit < (1 << n); bit++)
    {
        if (__builtin_popcount(bit) < k)
        {
            continue;
        }

        vector<int> s(1, 0);
        for (int i = 0; i < n; i++)
        {
            if (bit & (1 << i))
            {
                s.push_back(i);
            }
        }

        vector<ll> b = a;
        ll c = 0;
        for (int is = 1; is < s.size(); is++)
        {
            ll m = LLONG_MIN;
            for (int i = s[is - 1]; i < s[is]; i++)
            {
                m = max(m, b[i]);
            }

            if (m >= b[s[is]])
            {
                c += (m + 1 - b[s[is]]);
                b[s[is]] = m + 1;
            }
        }

        cmin = min(cmin, c);
    }

    cout << cmin << endl;

    return 0;
}