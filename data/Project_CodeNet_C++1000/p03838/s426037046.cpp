#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll x, y;
ll ans = 2e15;

void dfs(ll cur , ll depth, ll tim) {

    if(cur == y)ans = min(ans, tim);
    if(depth == 10)return;

    dfs(-cur, depth + 1, tim + 1);
    if(cur < y) {
        dfs(y, depth + 1, tim + (y - cur));
    }

    if(cur < -y) {
        dfs(-y, depth + 1, tim + (-y - cur));
    }
}

int main()
{
    cin >> x >> y;
    dfs(x, 0, 0);
    cout << ans << endl;
}