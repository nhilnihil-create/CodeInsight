#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define LINF (ll)1e18
#define INF (int)1e9
#define ll_1e9 (ll)1e9
using namespace std;

using P = pair<ll,ll>;
using PQ = priority_queue<P,vector<P>,greater<P>>;


struct edge{
    ll to,cost;  
};

void dijkstra(vector<vector<edge> > &G,vector<ll> &d,ll s){
    PQ que;
    fill(d.begin(),d.end(), LINF);
    d[s] = 0;
    que.push(P(0,s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        ll v = p.second;
        if(d[v] < p.first) continue;

        rep(i,0,G[v].size()){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to],e.to));
            }

        }
    }


}

int main(){
    ll n;
    cin >> n;
    vector<vector<edge> > G(n);
    vector<ll> d(n);

    ll a,b,c;
    edge e;
    rep(i,0,n-1){
        cin >> a >> b >> c;
        e.to = b-1;
        e.cost = c;
        G[a-1].push_back(e);
        e.to = a-1;
        G[b-1].push_back(e);
    }

    

    ll q,k;
    cin >> q >> k;
    dijkstra(G,d,k-1);

    rep(i,0,q){
        ll x,y;
        cin >> x >> y;
        cout << d[x-1] + d[y-1] << endl;
    }
    
 
    return 0;
}
