#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

ll n, m, cnt, ans, cnt2, ans2;
bool v[2005];
bool vv;
vector<ll> ve[2005];

void dfs(ll p, ll q)
{
    if(v[p]) return;
    if(q == m + 1 && vv) cnt2++;
    else if(q <= m) v[p] = true, cnt++;
    if(q >= m + 1) return;
    if(q >= m && !vv) return;
    for(ll i = 0; i < ve[p].size(); i++)
    {
        dfs(ve[p][i], q + 1);
        if(q == 0) ans2 = max(ans2, cnt2), cnt2 = 0;
    }
}

int main()
{
    cin>>n>>m;
    if(m % 2 == 1) vv = true;
    m /= 2;
    for(ll i = 0; i < n - 1; i++)
    {
        ll t1, t2;
        scanf("%lld%lld", &t1, &t2);
        ve[t1].push_back(t2);
        ve[t2].push_back(t1);
    }
    for(ll i = 1; i <= n; i++)
    {
        cnt = 0;
        for(ll j = 1; j <= n; j++) v[j] = false;
        dfs(i, 0);
        ans = max(ans, cnt + ans2);
        ans2 = 0;
    }
    cout<<n - ans<<endl;
    return 0;
}
