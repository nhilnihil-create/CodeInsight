#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define mod 998244353
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pi pair<ll,ll>
using namespace std;
const ll N=500010;

vector<ll> ans;
vector<ll> adj[N];

int vis[N][11];

void func(ll v,ll d,ll c)
{
    if(vis[v][d]==1){return;}
    vis[v][d]=1;
    if(d==0){ans[v]=c;return;}
    func(v,d-1,c);
    for(auto u:adj[v]){
        func(u,d-1,c);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;++i){
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ll q;
    cin>>q;
    vector<pair<ll,pi> > query(q);
    for(ll i=0;i<q;++i){
        cin>>query[i].first>>query[i].second.first>>query[i].second.second;
    }
    reverse(query.begin(),query.end());

    ans.resize(n+1,0);

    for(ll i=1;i<=n;++i){
        for(ll j=0;j<=10;++j){
            vis[i][j]=0;
        }
    }

    for(ll i=0;i<q;++i)
    {
        ll v=query[i].first;
        ll d=query[i].second.first;
        ll c=query[i].second.second;
        func(v,d,c);
    }
    for(ll i=1;i<=n;++i){
        cout<<ans[i]<<endl;
    }

    return (0);
}
