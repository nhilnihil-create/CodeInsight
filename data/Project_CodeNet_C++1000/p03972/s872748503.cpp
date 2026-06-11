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
#define mp make_pair
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
constexpr double PI = 3.14159265358979323846;
constexpr int di[] = {0, 0, 1, -1};
constexpr int dj[] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int w, h;
    ll p[112345], q[112345];

    cin >> w >> h;
    REP(i, w)
    cin >> p[i];
    REP(i, h)
    cin >> q[i];

    sort(p, p + w);
    sort(q, q + h);

    p[w] = INT_MAX;
    q[h] = INT_MAX;

    ll res = 0;

    int i = 0;
    int j = 0;

    while (i < w || j < h)
    {
        if (p[i] < q[j])
        {
            res += p[i] * (h + 1 - j);

            i++;
        }
        else
        {
            res += q[j] * (w + 1 - i);

            j++;
        }
    }

    cout << res << endl;

    return 0;
}