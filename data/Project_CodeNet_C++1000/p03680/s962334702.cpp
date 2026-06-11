#include <bits/stdc++.h>
using namespace std;

bool visited[(int) (1e5 + 2)];
int g[(int) (1e5 + 2)];
int dfs(int curr, int c)
{
// cout << "at: " << curr << endl;
    if (curr == 2)
    {
        printf("%d\n", c-1);
        return true;
    }
    if (visited[curr])
    {
        return false;
    }

    visited[curr]  = true;
    return dfs(g[curr], c + 1);
}
int main()
{
    int n;
    cin >> n;
    for (int i=1; i <= n; i++)
    {
        cin >> g[i];
    }
    if (dfs(1, 1))
    {
        return 0;
    }
    cout << -1 << endl;
}
