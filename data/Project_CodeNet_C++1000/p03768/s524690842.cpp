#include <iostream>
#include <cstring>
#include <vector>

#define ll long long
using namespace std;
#define pb push_back
const int N = 1e5 + 5;

inline int read() {
    int x = 0; char ch = getchar();
    for (; !isdigit(ch); ch = getchar());
    for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
    return x;
}

void W(int x) { if (x >= 10) W(x / 10); putchar(x % 10 + '0'); }

vector<int> g[N];
int mx[N], n, col[N], Q, d[N], c[N], m, p[N];

void dfs(int x) {
    if (!col[x]) col[x] = c[Q];
    for (int i : g[x]) if (mx[x] - 1 > mx[i]) mx[i] = mx[x] - 1, dfs(i);
}

int main() {
    memset(mx, -1, sizeof(mx));

    n = read(), m = read();
    for (int i = 1, uu, vv; i <= m; i++)
        uu = read(), vv = read(), g[uu].pb(vv), g[vv].pb(uu);
    Q = read();
    for (int i = 1; i <= Q; i++) p[i] = read(), d[i] = read(), c[i] = read();

    for (; Q; Q--) if (d[Q] > mx[p[Q]]) mx[p[Q]] = d[Q], dfs(p[Q]);

    for (int i = 1; i <= n; i++) W(col[i]), puts("");
    return 0;
}