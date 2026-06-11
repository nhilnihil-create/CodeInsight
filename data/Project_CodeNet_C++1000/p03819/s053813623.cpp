#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <cstring>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define INF 1e18
#define MOD 1e9 + 7

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

int br[112345], bl[112345], bit_n;

int bit_sum(int i, int bit[])
{
    int s = 0;
    while (i > 0)
    {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void bit_add(int i, int x, int bit[])
{
    while (i <= bit_n)
    {
        bit[i] += x;
        i += i & -i;
    }
}

int main()
{
    int n, m, l[312345], r[312345];
    P p[312345];

    cin >> n >> m;
    REP(i, n)
    {
        cin >> l[i] >> r[i];
        p[i] = {(r[i] - l[i] + 1), i};
    }

    p[n] = {1e9, 0};

    for (int i = 0; i <= m; i++)
    {
        bl[i] = 0;
        br[i] = 0;
    }

    bit_n = m + 10;

    sort(p, p + n);

    int al = n;

    int pi = 0;

    for (int i = 1; i <= m; i++)
    {
        int res = al;
        for (int j = 0; j <= m; j += i)
        {
            int tmp = n;
            tmp -= bit_sum(j + 1, br);
            tmp -= n - bit_sum(j + 2, bl);

            res += tmp;
        }

        cout << res << endl;

        while (p[pi].first < i + 1)
        {
            bit_add(l[p[pi].second] + 2, 1, bl);
            bit_add(r[p[pi].second] + 2, 1, br);
            pi++;
            al--;
        }
    }

    return 0;
}