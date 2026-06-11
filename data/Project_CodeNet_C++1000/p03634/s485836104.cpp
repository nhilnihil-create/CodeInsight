#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

void dijkstra(vector<vector<pair<long long,long long>>> &g, vector<long long> &dist, long long st){
    long long INF=1e17;
    long long n=g.size();
    dist.assign(n,INF);
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
    dist[st]=0;
    pq.emplace(dist[st],st);
    while(!pq.empty()) {
        pair<long long,long long> p=pq.top();
        pq.pop();
        long long v=p.second;
        long long d=p.first;
        if(dist[v] < d) continue;
        for(auto &np:g[v]) {
            long long nv=np.first;
            long long nd=np.second;
            if(dist[nv]>dist[v]+nd){
                dist[nv]=dist[v]+nd;
                pq.push(make_pair(dist[nv],nv));
            }
        }
    }
}

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<vector<pair<ll,ll>>> g(n);
    for(ll i = 0; i < n-1; i++) {
        ll a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
    }
    ll q,k;
    cin >> q >> k;
    k--;
    vector<ll> d(n);
    dijkstra(g,d,k);

    for(ll i = 0; i < q; i++) {
        ll x,y;
        cin >> x >> y;
        x--;
        y--;
        ll dist=d[x]+d[y];
        cout << dist << "\n";
    }

    return 0;
}