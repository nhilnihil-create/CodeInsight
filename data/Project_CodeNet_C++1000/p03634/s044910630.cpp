#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};

int main(void){
    ll n;
    cin >> n;
    vector<vector<ll>> g(n+1);
    map<p, ll> I{};
    for(ll i = 0; i < n-1; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(b);
        g[b].push_back(a);
        I[p(a,b)] = c; I[p(b,a)] = c;
    }
    ll q, k;
    cin >> q >> k;
    vector<p> vp;
    for(ll i = 0; i < q; i++){
        ll a, b;
        cin >> a >> b;
        vp.push_back(p(a, b));
    }
    vector<ll> dist(n+1, -1);
    queue<ll> que;
    dist[k] = 0;
    que.push(k);
    while(!que.empty()){
        ll v = que.front();
        que.pop();
        for(ll nv : g[v]){
            if(dist[nv]!=-1) continue;
            dist[nv] = dist[v]+I[p(v, nv)];
            que.push(nv);
        }
    }
    for(ll i = 0; i < q; i++){
        ll a = vp[i].first, b = vp[i].second;
        cout << dist[a]+dist[b] << endl;
    }
    return 0;
}
