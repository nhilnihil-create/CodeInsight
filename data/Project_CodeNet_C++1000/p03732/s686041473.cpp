#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    vector<int> v[4];

    ll n, limit;
    cin >> n >> limit;
    ll val, w1;
    cin >> w1 >> val;
    v[0].push_back(val);
    rep(i, n - 1)
    {
        ll w;
        cin >> w >> val;
        v[w - w1].push_back(val);
    }
    rep(i, 4) sort(ALL(v[i]), greater<int>());
    ll maxv = 0;

    rep(i, v[0].size() + 1)
    {
        ll v0 = (!v[0].empty() ? accumulate(v[0].begin(), v[0].begin() + i, 0) : 0);
        rep(j, v[1].size() + 1)
        {
            ll v1 = (!v[1].empty() ? accumulate(v[1].begin(), v[1].begin() + j, 0) : 0);
            rep(k, v[2].size() + 1)
            {
                ll v2 = (!v[2].empty() ? accumulate(v[2].begin(), v[2].begin() + k, 0) : 0);
                rep(l, v[3].size() + 1)
                {
                    ll v3 = (!v[3].empty() ? accumulate(v[3].begin(), v[3].begin() + l, 0) : 0);
                    if (i * w1 + j * (w1 + 1) + k * (w1 + 2) + l * (w1 + 3) <= limit)
                        maxv = max(maxv, v0 + v1 + v2 + v3);
                }
            }
        }
    }

    OP(maxv);

    return 0;
}