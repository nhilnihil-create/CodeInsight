#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N; cin >> N;
    vector<vector<pair<ll,ll>>> G(N+1);
    rep(i, 0, N-1){
        ll v, u, w;
        cin >> v >> u >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    ll Q, K;
    cin >> Q >> K;
    ll srt = K;
    vector<ll> d(N+1, 1e18);
    
    /* dijkstra's scope */{
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> que;
        que.push({0, srt});
        d[srt] = 0;
        while(!que.empty()){
            auto q = que.top();
            que.pop();
            if(q.first > d[q.second]) continue;
            for(auto g : G[q.second]){
                if(d[g.first] <= q.first + g.second) continue;
                d[g.first] = q.first + g.second;
                que.push({d[g.first], g.first});
            }
        }
    }

    rep(q, 0, Q){
        ll x, y;
        cin >> x >> y;
        cout << d[x] + d[y] << endl;
    }
    return 0;
}