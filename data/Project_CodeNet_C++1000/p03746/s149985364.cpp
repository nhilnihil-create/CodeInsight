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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, a[112345], b[112345];
    bool used[112345] = {false};
    vector<int> g[112345], num, res;

    cin >> n >> m;

    REP(i, m)
    num.push_back(0);

    REP(i, m)
    {
        cin >> a[i] >> b[i];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);

        num[a[i]]++;
        num[b[i]]++;
    }

    int s = a[0], e = b[0];
    used[s] = true;
    used[e] = true;

    res.push_back(s);
    res.push_back(e);

    while (true)
    {
        int s_ = 0, e_ = 0;
        while (s_ < g[s].size() && used[g[s][s_]])
            s_++;

        while (e_ < g[e].size() && used[g[e][e_]])
            e_++;

        if (s_ == g[s].size() && e_ == g[e].size())
            break;

        if (s_ == g[s].size())
        {
            e = g[e][e_];
            used[e] = true;

            res.push_back(e);
        }
        else
        {
            s = g[s][s_];
            used[s] = true;

            res.insert(res.begin(), s);
        }
    }

    cout << res.size() << endl;

    REP(i, res.size())
    {
        cout << res[i];
        if (i < res.size() - 1)
            cout << " ";
    }

    cout << endl;

    return 0;
}