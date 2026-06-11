#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int a, b, c, d, e, f;
int vis[35][3005];

int dfs(int water, int sugar)
{
    if (water * 100 + sugar > f)
        return 0;
    if (sugar > water * e)
        return 0;
    if (vis[water][sugar])
        return 1;
    
    dfs(water + a, sugar);
    dfs(water + b, sugar);
    dfs(water, sugar + c);
    dfs(water, sugar + d);
    return vis[water][sugar] = 1;
}

ii bst(ii a, ii b)
{
    int x, y, p, q;
    tie(x, y) = a;
    tie(p, q) = b;
    if (100 * y * (p + q) > 100 * q * (x + y))
        return a;
    return b;
}

int main()
{
    cin >> a >> b >> c >> d >> e >> f;
    dfs(0, 0);
    ii sol;
    for (int i = 0; i <= 30; ++i)
        for (int j = 0; i + j <= f; ++j)
            if (vis[i][j])
                sol = bst(sol, {i * 100, j});
    cout << sol.first + sol.second _ sol.second;
}
