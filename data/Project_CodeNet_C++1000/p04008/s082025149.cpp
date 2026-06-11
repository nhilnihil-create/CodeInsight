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

V g[112345];
int n, k;
int res = 0;
bool d[112345];

int dfs(int p)
{
    int rnk = 1;
    for (int i : g[p])
        rnk = max(rnk, dfs(i) + 1);

    if (d[p])
        return 0;

    if (rnk == k)
    {
        res++;
        rnk = 0;
    }

    return rnk;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    fill(d, d + n, false);

    REP(i, n)
    {
        int a;
        cin >> a;
        if (i == 0)
            res += a != 1;
        else
        {
            g[a].push_back(i + 1);
            if (a == 1)
                d[i + 1] = true;
        }
    }

    d[1] = true;

    dfs(1);

    cout << res << endl;

    return 0;
}