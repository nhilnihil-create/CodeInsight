#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

ll n;
ll a[100005];
ll b[100005];
ll c[100005];
queue<ll> qu;
vector<ll> ve[100005];

int main()
{
    scanf("%lld", &n);
    for(ll i = 2; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        b[a[i]]++;
    }
    for(ll i = 1; i <= n; i++)
    {
        if(b[i] == 0)
        {
            qu.push(i);
        }
    }
    while(!qu.empty())
    {
        ll t = qu.front();
        qu.pop();
        ll mx = 0;
        if(ve[t].size() == 0) c[t] = 0;
        else
        {
            sort(ve[t].begin(), ve[t].end(), greater<ll>());
            for(ll i = 0; i < ve[t].size(); i++)
            {
                mx = max(mx, ve[t][i] + i + 1);
            }
            c[t] = mx;
        }
        b[a[t]]--;
        ve[a[t]].push_back(c[t]);
        if(b[a[t]] == 0) qu.push(a[t]);
        if(t == 1)
        {
            printf("%lld", c[1]);
            return 0;
        }
    }
    return 0;
}
