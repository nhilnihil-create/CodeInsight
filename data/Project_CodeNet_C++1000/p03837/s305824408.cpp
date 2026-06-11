#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

using P = pair<int,int>;
using T = tuple<int,int,int>; // 距離　頂点　親
using Graph = vector<vector<P>>;

int main(){
    int n, m; cin >> n >> m;

    Graph G(n);
    map<P,int> mp;
    rep(i,m){
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        G[a].push_back(P(b,c));
        G[b].push_back(P(a,c));
        mp[P(a,b)] = i;
        mp[P(b,a)] = i;
    }

    vector<bool> used(m,false);

    rep(i,n){
        vector<int> dist(n,100100100); dist[i] = 0; // 最短距離
        priority_queue<T, vector<T>, greater<T>> que; // 小さい順に取り出す
        que.push(T(0, i, -1));
        while (!que.empty()){
            T t = que.top(); que.pop();
            int d, v, p; tie(d, v, p) = t;
            if (dist[v] < d) continue; // 最短距離ではない
            if(p != -1) used[mp[P(p,v)]] = true; // 辺を使う
            for (auto e : G[v]) {
                if (dist[e.first] > dist[v] + e.second) {
                    dist[e.first] = dist[v] + e.second;
                    que.push(T(dist[e.first], e.first, v));
                }
            }
        }
    }

    int ans = m;
    rep(i,m) if(used[i]) ans--;

    cout << ans << endl;
}

