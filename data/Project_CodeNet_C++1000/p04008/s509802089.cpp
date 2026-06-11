#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    vector<set<int>> tree(n);
    int ans = 0;
    if(a[0] != 0) ans++;
    for(int i = 1; i < n; i++)
    {
        tree[a[i]].insert(i);
    }
    function<int(int)> dfs = [&](int v)
    {
        int num = 0;
        for(int nx : tree[v])
        {
            num = max(num, dfs(nx));
        }
        if(v != 0 && tree[0].find(v) == tree[0].end() && num == k-1)
        {
            ans++;
            return 0;
        }
        return num + 1;
    };
    dfs(0);
    cout << ans << endl;
}
