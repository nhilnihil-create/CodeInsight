#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    struct edge{
        ll from;
        ll to;
        ll cost;
    };

    ll n,m;
    cin>>n>>m;
    vector<edge> E(m);
    rep(i,m){
        ll s,t,d;
        cin>>s>>t>>d;
        s--; t--;
        E[i]={s,t,-d};
    }

    vector<ll> dist(n,INF);
    dist[0]=0;
    rep(i,n*2){
        bool update=false;
        for(auto x:E){
            if(dist[x.from] != INF && dist[x.from]+x.cost < dist[x.to]){
                update=true;
                dist[x.to] = dist[x.from]+x.cost;
                if(i>=n && x.to == n-1){
                    cout<<"inf"<<endl;
                    return 0;
                }
            }
        }
    }

    cout<<-dist[n-1]<<endl;
    
    return 0;
}