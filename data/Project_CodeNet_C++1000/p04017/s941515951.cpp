#include <iostream>
using namespace std;

#define int long long
const int N = 1e5+5, LOGN = 20, INF = 1e18+9;
int n, q, u, v, dist;
int a[N], jump[LOGN][N];

void init()
{
    for (int i = 1; i <= LOGN; i++)
        for (int j = 1; j <= n; j++)
            jump[i][j] = jump[i-1][jump[i-1][j]];
}

int solve(int u, int v)
{
    int ans = 0;
    for (int j = LOGN; j >= 0; j--)
    {
        if (jump[j][u] < v)
        {
        u = jump[j][u];
        ans += (1<<j);
        }
    }
    return ans+1;
}

signed main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> dist;
    for (int i = 1; i <= n; i++)
    {
        int l = i;
        for(int j = 20; j >= 0; j--)
        {
            int r = l + (1<<j);
            if (r > n) continue;
            else
            {
                if (a[r] - a[i] <= dist) l += (1<<j);
            }
        }
        jump[0][i] = l;
    }
    init();
//    for (int i = 1; i <= n; i++)
//        cout << i << ' ' << jump[0][i] << ' ' << jump[1][i] << ' ' << jump[2][i] << endl;
    cin >> q;
    while(q--)
    {
        cin >> u >> v;
        if (v < u)
            swap(u,v);
//        solve(u,v);
        cout << solve(u,v) << endl;
    }
}
/*
9
1 3 6 13 15 18 19 29 31
10
6
3 4
3 5
3 6
3 7
3 8
3 9
*/
/*
9
1 3 6 13 15 18 19 29 31
10
1
1 2
*/
