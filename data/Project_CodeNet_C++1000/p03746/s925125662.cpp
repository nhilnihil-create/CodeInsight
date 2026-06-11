#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

ll n, m;
vector<ll> ve[100005];
bool v[100005];
vector<ll> ans1, ans2;

int main()
{
    scanf("%lld%lld", &n, &m);
    for(ll i = 0; i < m; i++)
    {
        ll t1, t2;
        scanf("%lld%lld", &t1, &t2);
        ve[t1].push_back(t2);
        ve[t2].push_back(t1);
    }
    ll now = 1;
    while(1)
    {
        bool vv = false;
        v[now] = true;
        ans1.push_back(now);
        for(ll i = 0; i < ve[now].size(); i++)
        {
            if(v[ve[now][i]]) continue;
            vv = true;
            now = ve[now][i];
            break;
        }
        if(!vv) break;
    }
    now = 1;
    while(1)
    {
        bool vv = false;
        v[now] = true;
        ans2.push_back(now);
        for(ll i = 0; i < ve[now].size(); i++)
        {
            if(v[ve[now][i]]) continue;
            vv = true;
            now = ve[now][i];
            break;
        }
        if(!vv) break;
    }
    printf("%lld\n", (ll)ans1.size() + (ll)ans2.size() - 1);
    for(ll i = ans1.size() - 1; i > 0; i--)
    {
        printf("%lld ", ans1[i]);
    }
    for(ll i = 0; i < ans2.size(); i++)
    {
        printf("%lld ", ans2[i]);
    }
    return 0;
}
