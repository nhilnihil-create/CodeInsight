#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int INF = 1e9+10;
int main()
{
    int n;
    cin >> n;
    vector<set<int>> s(n);
    for(int i = 1; i < n; i++)
    {
        int a;
        cin >> a;
        a--;
        s[a].insert(i);
    }
    function<int(int)> dfs = [&](int v)
    {
        multiset<int> tmp;
        for(int nx : s[v])
        {
            tmp.insert(dfs(nx));
        }
        int cnt = 1;
        int res = 0;
        for(auto itr = tmp.rbegin(); itr != tmp.rend(); itr++)
        {
            res = max(res, *itr + cnt);
            cnt++;
        }
        return res;
    };
    cout << dfs(0) << endl;
}
