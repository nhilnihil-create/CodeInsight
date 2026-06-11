#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

#define mk make_pair
#define sc second
#define fr first
#define pb emplace_back
#define all(s) s.begin(), s.end()
#define sz(s) ( (int)s.size() )

using namespace std;

const int N = 2e5 + 5;

int n, m1, m2, x, y, u1[N], u2[N], cnt;

vector < vector <int> > g1, g2;

void dfs1 (int v)
{
    u1[v] = cnt;
    for (int i = 0; i < g1[v].size(); i++)
    {
        int to = g1[v][i];
        if ( !u1[to] )
            dfs1(to);
    }
}
void dfs2 (int v)
{
    u2[v] = cnt;
    for (int i = 0; i < g2[v].size(); i++)
    {
        int to = g2[v][i];
        if ( !u2[to] )
            dfs2(to);
    }
}
map <pair <int, int> , int > mp;

main ()
{
    cin >> n >> m1 >> m2;

    g1.resize(n + 1);
    g2.resize(n + 1);

    for (int i = 1; i <= m1; i++)
    {
        scanf("%d%d", &x, &y);
        g1[x].pb(y);
        g1[y].pb(x);
    }
    for (int i = 1; i <= m2; i++)
    {
        scanf("%d%d", &x, &y);
        g2[x].pb(y);
        g2[y].pb(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!u1[i])
        {
            cnt++;
            dfs1( i );
        }
    }
    cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!u2[i])
        {
            cnt++;
            dfs2( i );
        }
        mp[ mk(u1[i], u2[i]) ]++;
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", mp[ mk( u1[i], u2[i] ) ]);
    }

}
