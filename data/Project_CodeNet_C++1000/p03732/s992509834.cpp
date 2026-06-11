#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)

using ll = long long;
#define INF 1e9

int N, W;
vector<vector<int>> bg;

ll addbg(int a, int b, int c, int d)
{
    ll sum = 0;
    REP(i, a)
    {
        sum += bg[0][i];
    }
    REP(i, b)
    {
        sum += bg[1][i];
    }
    REP(i, c)
    {
        sum += bg[2][i];
    }
    REP(i, d)
    {
        sum += bg[3][i];
    }
    return sum;
}

int main()
{
    cin >> N >> W;
    vector<ll> w(N), v(N);
    bg.resize(4);
    REP(i, N)
    {
        cin >> w[i] >> v[i];
        bg[w[i] - w[0]].push_back(v[i]);
    }
    REP(i, 4)
    {
        sort(bg[i].begin(), bg[i].end(), greater<int>());
    }
    ll ans = 0;
    REP(i, bg[0].size() + 1)
    {
        REP(j, bg[1].size() + 1)
        {
            REP(k, bg[2].size() + 1)
            {
                REP(l, bg[3].size() + 1)
                {
                    ll weight = w[0] * i + (w[0] + 1) * j + (w[0] + 2) * k + (w[0] + 3) * l;
                    if (weight <= W)
                    {
                        ans = max(ans, addbg(i, j, k, l));
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}