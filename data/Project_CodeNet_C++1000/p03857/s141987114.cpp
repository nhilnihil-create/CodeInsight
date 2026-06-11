#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>
#include <numeric>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define INF (ll)1e18
#define MOD (ll)1e9 + 7

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

int par[212345], rnk[212345];
int n, k, l, p[112345], q[112345], r[112345], s[112345], a[212345], b[212345];

void init()
{
    REP(i, n)
    {
        par[i] = i;
        rnk[i] = 0;
    }
}

int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;

    if (rnk[x] < rnk[y])
    {
        par[x] = y;
    }
    else
    {
        par[y] = x;
        if (rnk[x] == rnk[y])
            rnk[x]++;
    }
}

int main()
{
    cin >> n >> k >> l;
    map<P, int> mp;
    init();
    REP(i, k)
    {
        cin >> p[i] >> q[i];
        unite(p[i] - 1, q[i] - 1);
    }
    REP(i, n)
    {
        a[i] = find(i);
    }

    init();

    REP(i, l)
    {
        cin >> r[i] >> s[i];
        unite(r[i] - 1, s[i] - 1);
    }
    REP(i, n)
    {
        b[i] = find(i);

        mp[make_pair(a[i], b[i])]++;
    }

    /*
    REP(i, n)
    {
        cout << a[i] << (i == n - 1 ? "\n" : " ");
    }

    REP(i, n)
    {
        cout << b[i] << (i == n - 1 ? "\n" : " ");
    }
    */

    REP(i, n)
    {
        cout << mp[make_pair(a[i], b[i])] << (i == n - 1 ? "\n" : " ");
    }

    return 0;
}