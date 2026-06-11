#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,d[100005],otac[100005],broj[100005];
vector<ll> adj[100005];

void dfs1(ll tr,ll pr)
{
    for(auto u: adj[tr])
    {
        if(u!=pr)
        {
            otac[u]=tr;
            d[u]+=d[tr]+1;
            dfs1(u,tr);
        }
    }

}

void brojac(ll tr,ll pr)
{
    broj[tr]++;
    for(auto u:adj[tr])
    {
        if((u!=pr))
        {
            brojac(u,tr);
            broj[tr]+=broj[u];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(ll i=1;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    otac[1]=-1;
    dfs1(1,0);

    ll x=d[n]/2-(d[n]%2==0);
    ll ind=n;
    while(x)
    {
        ind=otac[ind];
        x--;
    }

    brojac(1,0);

    //cout<<broj[ind]<<endl;

    if((n-2)-(broj[ind]-1)<=(broj[ind]-1))
        cout<<"Snuke"<<endl;
    else
        cout<<"Fennec"<<endl;

    return 0;
}
