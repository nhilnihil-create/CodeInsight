#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <cmath>
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
constexpr int di[] = {0, 0, 1, -1};
constexpr int dj[] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t[112345], a[112345];

    cin >> n;
    REP(i, n)
    cin >> t[i + 1];
    REP(i, n)
    cin >> a[i + 1];

    int s = -1;

    t[0] = 0;
    t[n + 1] = MOD;
    a[0] = MOD;
    a[n + 1] = 0;

    int mat = 0;
    int maa = 0;
    REP(i, n)
    {
        mat = max(mat, t[i + 1]);
        maa = max(maa, a[i + 1]);
    }

    if (mat != maa)
    {
        cout << 0 << endl;
        return 0;
    }

    REP(i, n)
    {
        if (a[i + 1] == t[i + 1] && a[i + 1] == mat)
        {
            s = i + 1;
            break;
        }
    }

    if (s == -1)
    {
        cout << 0 << endl;
        return 0;
    }

    ll res = 1;

    for (int i = 1; i < s; i++)
    {
        if (t[i - 1] < t[i])
        {
        }
        else
        {
            (res *= t[i]) %= MOD;
        }
    }

    for (int i = n; i > s; i--)
    {
        if (a[i + 1] < a[i])
        {
        }
        else
        {
            (res *= a[i]) %= MOD;
        }
    }

    cout << res << endl;

    return 0;
}