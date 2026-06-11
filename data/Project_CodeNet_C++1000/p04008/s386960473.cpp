#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
ll MOD = 1e9+7;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<set<int>> d(n);
    int ans = 0;
    int zero;
    cin >> zero;
    if(zero != 1) ans++;
    for(int i = 1; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        d[a[i]].insert(i);
    }
    d[0].insert(0);
    bitset<100010> bs;
    function<int(int)> dfs = [&](int v)
    {
        bs[v] = true;
        int m = 0;
        for(int nx : d[v])
        {
            if(bs[nx]) continue;
            m = max(m, dfs(nx));
        }
        if(d[0].find(v) == d[0].end() && m+1 == k)
        {
            ans++;
            return 0;
        }
        else return m+1;
    };
    bs[0] = true;
    dfs(0);
    cout << ans << endl;
}