#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 13;
vector<int> wn[N], ls[N];
int dfs(int v)
{
    vector<int> uwu;
    for (int i : wn[v])
    {
        uwu.push_back(dfs(i));
    }
    sort(uwu.rbegin(), uwu.rend());
    int ans = 0;
    for (int i = 1; i <= uwu.size(); i++)
    {
        ans = max(ans, i + uwu[i - 1]);
    }
    return ans;
}
signed main()
{
#ifdef home
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#else
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int v;
        cin >> v;
        wn[v].push_back(i);
        ls[i].push_back(v);
    }
    cout << dfs(1);
}