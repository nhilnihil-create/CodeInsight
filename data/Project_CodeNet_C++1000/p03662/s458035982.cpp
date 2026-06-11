#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1.1e5;

int N;
vector <int> edge[MAXN];
int dep[MAXN];
int ndep[MAXN];

void gogo (int cloc, int last)
{
    for (int neigh : edge[cloc])
    {
        if (neigh == last) continue;
        dep[neigh] = dep[cloc] + 1;
        gogo (neigh, cloc);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;

        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    dep[0] = 0;
    gogo (0, -1);
    for (int i = 0; i < N; i++)
        ndep[i] = dep[i];

    dep[N-1] = 0;
    gogo (N - 1, -1);

    int nc = 0;
    for (int i = 0; i < N; i++)
        if (ndep[i] <= dep[i])
            nc++;

    if (nc * 2 > N)
        cout << "Fennec\n";
    else
        cout << "Snuke\n";
}