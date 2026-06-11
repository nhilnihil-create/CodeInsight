#include <iostream>
#include <vector>
#include <deque>
#include <math.h>
#include <set>
#include <iomanip>
#include <time.h>
#include <list>
#include <stdio.h>
#include <queue>
#include <map>
#include <algorithm>
#include <assert.h>
#include <memory.h>

#define mk make_pair
#define sc second
#define fr first
#define pb emplace_back
#define all(s) s.begin(), s.end()
#define sz(s) ( (int)s.size() )
#define ok puts("OK");
#define int long long

using namespace std;

const int N = 305, inf = 1e18;

int n, ar[N][N], d[N][N], ans;

vector <pair <int, pair <int, int> > > vec;
main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%lld", &ar[i][j]);

            if (i < j)
                vec.pb( mk( ar[i][j], mk(i, j) ) );

            if (i != j) d[i][j] = inf;
        }
    }
    sort( all(vec) );

    for (int i = 0; i < vec.size(); i++)
    {
        int len = vec[i].fr, x = vec[i].sc.fr, y = vec[i].sc.sc;
        if ( d[x][y] == inf || d[x][y] > ar[x][y] )
        {
            ans += len;

            d[x][y] = d[y][x] = len;

            for (int k = 1; k <= n; k++)
                for (int j = 1; j <= n; j++)
                {
                    d[k][j] = min (d[k][j], d[k][x] + d[x][j]);
                }

            for (int k = 1; k <= n; k++)
                for (int j = 1; j <= n; j++)
                {
                    d[k][j] = min (d[k][j], d[k][y] + d[y][j]);
                }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ar[i][j] != d[i][j])
            {
                puts("-1");
                return 0;
            }
        }
    }
    cout << ans << endl;
}
