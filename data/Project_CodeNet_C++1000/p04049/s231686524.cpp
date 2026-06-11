// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 2009;
int n, k, D[N];
vector < int > Adj[N];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i ++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        Adj[v].push_back(u);
        Adj[u].push_back(v);
    }
    int Mx = 0;
    if (k % 2 == 0)
    {
        for (int centre = 1; centre <= n; centre ++)
        {
            queue < int > qu;
            memset(D, 63, sizeof(D));
            qu.push(centre);
            D[centre] = 0;
            while (qu.size())
            {
                int v = qu.front();
                qu.pop();
                for (int u : Adj[v])
                    if (D[u] > D[v] + 1)
                        D[u] = D[v] + 1, qu.push(u);
            }
            int Cnt = 0;
            for (int i = 1; i <= n; i ++)
                if (D[i] <= k / 2)
                    Cnt ++;
            Mx = max(Mx, Cnt);
        }
    }
    else
    {
        for (int centre = 1; centre <= n; centre ++)
        {
            for (int centre2 : Adj[centre])
            {
                queue < int > qu;
                memset(D, 63, sizeof(D));
                D[centre] = 1;
                D[centre2] = 1;
                qu.push(centre);
                qu.push(centre2);
                while (qu.size())
                {
                    int v = qu.front();
                    qu.pop();
                    for (int u : Adj[v])
                        if (D[u] > D[v] + 1)
                            D[u] = D[v] + 1, qu.push(u);
                }
                int Cnt = 0;
                for (int i = 1; i <= n; i ++)
                    if (D[i] <= (k + 1) / 2)
                        Cnt ++;
                Mx = max(Mx, Cnt);

            }
        }
    }
    return !printf("%d\n", n - Mx);
}