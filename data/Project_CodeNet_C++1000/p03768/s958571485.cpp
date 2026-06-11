#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

ll n, m, Q;
vector<ll> ve[100005];
ll c[100005];
ll d[100005];
ll x[100005], y[100005], z[100005];
queue<ll> qu, qc, qi;

int main()
{
    scanf("%lld%lld", &n, &m);
    while(m--)
    {
        ll t1, t2;
        scanf("%lld%lld", &t1, &t2);
        ve[t1].push_back(t2);
        ve[t2].push_back(t1);
    }
    scanf("%lld", &Q);
    for(ll i = 0; i < Q; i++)
    {
        ll t1, t2, t3;
        scanf("%lld%lld%lld", &x[i], &y[i], &z[i]);
    }
    for(ll i = 1; i <= n; i++) d[i] = -1;
    for(ll i = Q - 1; i >= 0; i--)
    {
        qi.push(x[i]), qc.push(z[i]), qu.push(y[i]);
        while(!qi.empty())
        {
            ll t1 = qi.front(), t2 = qc.front(), t3 = qu.front();
            qi.pop(), qc.pop(), qu.pop();
            if(c[t1] == 0) c[t1] = t2;
            if(d[t1] >= t3) continue;
            d[t1] = t3;
            if(t3 == 0) continue;
            for(ll j = 0; j < ve[t1].size(); j++)
            {
                qi.push(ve[t1][j]), qc.push(t2), qu.push(t3 - 1);
            }
        }
    }
    for(ll i = 1; i <= n; i++)
    {
        printf("%lld\n", c[i]);
    }
    return 0;
}
