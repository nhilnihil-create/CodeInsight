#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <set>
#include <cctype>
#include <bitset>
#include <type_traits>

#include <list>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define YES(j) cout << (j ? "YES" : "NO") << endl;
#define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
#define yes(j) std::cout << (j ? "yes" : "no") << endl;

int main(void)
{
    const int INF = 100000000;
    int n, m;
    cin >> n >> m;
    int a[1000], b[1000], c[1000];
    int dist[100][100];
    REP(i, m)
    {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
    }

    REP(i, n)
    {
        REP(j, n)
        {
            if (i == j)
                dist[i][j] = 0;
            else
            {
                dist[i][j] = INF;
            }
        }
    }

    REP(i, m)
    {
        dist[a[i]][b[i]] = min(dist[a[i]][b[i]], c[i]);
        dist[b[i]][a[i]] = min(dist[b[i]][a[i]], c[i]);
    }
    REP(k, n)
    {
        REP(i, n)
        {
            REP(j, n)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = m;
    REP(i, m)
    {
        bool shortest = false;
        REP(j, n)
        {
            if (dist[j][a[i]] + c[i] == dist[j][b[i]])
                shortest = true;
        }
        if (shortest)
            ans--;
    }
    cout << ans << endl;
}