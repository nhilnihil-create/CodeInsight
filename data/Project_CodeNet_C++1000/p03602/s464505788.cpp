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
#include <cstring>
#include <climits>

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
constexpr int dx[] = {0, 0, 1, -1};
constexpr int dy[] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll cost[310][310];
    vector<pair<int, P>> v;

    cin >> n;
    REP(i, n)
    REP(j, n)
    {
        int a;
        cin >> a;

        v.push_back(make_pair(a, make_pair(i + 1, j + 1)));

        cost[i + 1][j + 1] = INF;
    }

    SORT(v);

    for (int i = 1; i <= n; i++)
        cost[i][i] = 0;

    ll res = 0;

    for (auto p : v)
    {

        if (cost[p.second.first][p.second.second] == p.first)
            continue;

        if (cost[p.second.first][p.second.second] < p.first)
        {
            res = -1;
            break;
        }

        cost[p.second.first][p.second.second] = p.first;
        cost[p.second.second][p.second.first] = p.first;

        for (int i = 1; i <= n; i++)
        {
            cost[p.second.first][i] = min(cost[p.second.first][i], cost[i][p.second.second] + p.first);
            cost[i][p.second.first] = min(cost[i][p.second.first], cost[i][p.second.second] + p.first);
        }

        for (int i = 1; i <= n; i++)
        {
            cost[p.second.second][i] = min(cost[p.second.second][i], cost[i][p.second.first] + p.first);
            cost[i][p.second.second] = min(cost[i][p.second.second], cost[i][p.second.first] + p.first);
        }

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                cost[i][j] = min(cost[i][j], cost[i][p.second.second] + cost[j][p.second.first] + p.first);
                cost[i][j] = min(cost[i][j], cost[j][p.second.second] + cost[i][p.second.first] + p.first);
                cost[j][i] = min(cost[j][i], cost[i][p.second.second] + cost[j][p.second.first] + p.first);
                cost[j][i] = min(cost[j][i], cost[j][p.second.second] + cost[i][p.second.first] + p.first);
            }

        res += p.first;
    }

    cout << res << endl;

    return 0;
}