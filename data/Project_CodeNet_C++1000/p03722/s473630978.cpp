#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll> > > adj(n);
    vector<pair<ll, pair<ll, ll> > > edges;
    for(int i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, -c});
        edges.push_back({a - 1, {b - 1, -c}});
    }
    vector<ll> dist(n, 1e18);
    dist[0] = 0;
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < m; j++){
            if(dist[edges[j].first] < 1e18)
                dist[edges[j].second.first] = min(dist[edges[j].second.first], dist[edges[j].first] + edges[j].second.second);
        }
    ll ans = dist[n - 1];
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < m; j++){
            if(dist[edges[j].first] < 1e18)
                dist[edges[j].second.first] = min(dist[edges[j].second.first], dist[edges[j].first] + edges[j].second.second);
        }
    if(dist[n - 1] < ans){
        cout << "inf" << endl;
        return 0;
    }
    cout << -dist[n - 1] << endl;
}