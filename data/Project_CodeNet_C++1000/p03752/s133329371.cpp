#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/* next combination */
int next_combination(int sub)
{
    int x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}

void solve(int bit, vector<ll> a)
{

    return;
}

int main()
{
    int n = 0, k = 0;
    cin >> n >> k;

    vector<ll> a(n, 0);
    rep0(i, n)
    {
        cin >> a[i];
    }

    ll cntmin = LLONG_MAX;
    for (int bit = (1 << k) - 1; bit < (1 << n); ++bit)
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
        ll cnt = 0, m = LLONG_MIN;
        for (int i = 1; i <= k; i++)
        {
            for (int j = s[i - 1]; j < s[i]; j++)
            {
                m = max(m, b[j]);
            }

            if (a[s[i]] <= m)
            {
                cnt += m + 1 - b[s[i]];
                b[s[i]] = m + 1;
            }
        }

        // for (int i = 1; i <= k; i++)
        // {
        //     cout << a[s[i]] << " ";
        // }
        // cout << ": " << cnt << endl;

        cntmin = min(cnt, cntmin);
    }

    cout << cntmin << endl;

    return 0;
}