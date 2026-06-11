#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;

int main() {
    int n;
    cin >> n;
    vector<vector<P>> G(n);
    rep(i, n - 1){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }
    int q, k;
    cin >> q >> k;
    k--;

    const ll INF = 1001001001001001001;
    vector<ll> dist(n, INF);
    vector<bool> vis(n, false);
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(make_pair(k, 0));
    dist[k] = 0;
    while(!que.empty()){
        P v = que.top();
        que.pop();
        ll t = v.first;
        ll d = v.second;
        if(vis[t]) continue;
        vis[t] = true;
        dist[t] = d;
        for(P vv : G[t]){
            if(dist[vv.first] <= d + vv.second) continue;
            que.push(make_pair(vv.first, vv.second + d));
        }
    }

    rep(i, q){
        ll x, y;
        cin >> x >> y;
        x--; y--;
        cout << dist[x] + dist[y] << endl;
    }
    
}