#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> v[100010];

int dfs (int nod, int tata)
{
    int rez = 0;
    for (auto &it : v[nod])
    {
        if (it == tata) continue;

        rez ^= (dfs (it, nod) + 1);
    }

    return rez;
}

int main ()
{
   // freopen ("file.in", "r", stdin);

    int n;
    scanf ("%d", &n);

    for (int i = 1; i < n; ++i)
    {
        int x, y;
        scanf ("%d %d", &x, &y);

        v[x].push_back (y);
        v[y].push_back (x);
    }

    if (!dfs (1, 0)) printf ("Bob\n");
    else printf ("Alice\n");

    return 0;
}
