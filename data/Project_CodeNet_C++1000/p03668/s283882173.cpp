#include<bits/stdc++.h>

using namespace std;

int N, dp[100009];
vector < int > v[100009];

void dfs (int nod, int tata)
{
    for (auto it : v[nod])
        if (it != tata)
            dfs (it, nod), dp[nod] ^= (dp[it] + 1);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
dfs (1, -1);
if (dp[1]) printf ("Alice\n");
else printf ("Bob\n");
return 0;
}
