#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cassert>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
constexpr double PI = 3.14159265358979323846;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q, a[112345], b[112345], v[112345], d[112345], c[112345];
    P res[112345];
    V g[112345];

    cin >> n >> m;
    REP(i, m)
    {
        cin >> a[i] >> b[i];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    cin >> q;
    REP(i, q)
    cin >> v[i] >> d[i] >> c[i];

    fill(res, res + n + 1, make_pair(-1, -1));

    for (int i = q - 1; i >= 0; i--)
    {
        queue<int> que;

        que.push(v[i]);

        REP(j, d[i] + 1)
        {
            V vec;
            while (que.size())
            {
                vec.push_back(que.front());
                que.pop();
            }

            for (int k : vec)
            {
                if (res[k].first == -1)
                {
                    res[k].first = c[i];
                }

                if (res[k].second < d[i] - j)
                {
                    res[k].second = d[i] - j;
                    for (int l : g[k])
                        que.push(l);
                }
            }
        }
    }

    REP(i, n)
    {
        res[i + 1].first = max(0, res[i + 1].first);
        cout << res[i + 1].first << endl;
    }

    return 0;
}