#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, m;
vector <int> neigh[Maxn];
bool tk[Maxn];
int lft;
int bic, nonbic;
int col[Maxn];
ll res;

int Count(int v)
{
    if (tk[v]) return 0;
    tk[v] = true;
    int cnt = 1;
    for (int i = 0; i < neigh[v].size(); i++)
        cnt += Count(neigh[v][i]);
    return cnt;
}

bool Bic(int v, int c)
{
    if (col[v] != 0) return col[v] == c;
    col[v] = c;
    for (int i = 0; i < neigh[v].size(); i++)
        if (!Bic(neigh[v][i], -c)) return false;
    return true;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    lft = n;
    for (int i = 1; i <= n; i++) if (!tk[i]) {
        int siz = Count(i);
        if (siz == 1) { lft--; res += 2ll * lft + 1ll; }
        else if (Bic(i, 1)) bic++;
             else nonbic++;
    }
    while (nonbic > 0) {
        nonbic--;
        res += 2 * (bic + nonbic) + 1;
    }
    res += ll(bic) * bic * 2ll;
    cout << res << endl;
    return 0;
}
