#include<bits/stdc++.h>

using namespace std;

int sz, a, b, c, Sb, Sc, N, M, ap[100009];
bool Bip;
vector < int > v[100009];

void dfs (int nod, int col)
{
    if (ap[nod])
    {
        if (ap[nod] != col) Bip = 0;
        return ;
    }
    ap[nod] = col, sz ++;
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        dfs (*it, 3 - col);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
while (M --)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
for (int i=1; i<=N; i++)
    if (ap[i] == 0)
    {
        Bip = 1, sz = 0, dfs (i, 1);
        if (sz == 1) a ++;
        else
        if (Bip) b ++, Sb += sz;
        else c ++, Sc += sz;
    }
long long ans = 1LL * c * c + 1LL * a * a + 2LL * b * b + 2LL * b * c + 2LL * a * (Sb + Sc);
printf ("%lld\n", ans);
return 0;
}
