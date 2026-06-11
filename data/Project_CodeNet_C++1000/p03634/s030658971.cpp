#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001001001001;

ll N, Q, K, tmp=0;
vector<vector<pair<ll,ll>>> G;
vector<ll> ans;

void dijkstra(ll x) {
    vector<ll> color(N, INF);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> PQ;
    color[x] = 0;
    PQ.push(make_pair(color[x],x));
    while(!PQ.empty()) {
        pair<ll,ll> p = PQ.top();
        PQ.pop();
        if (color[p.second] < p.first) {
            continue;
        }
        for(int i=0;i<G[p.second].size();i++) {
            if(color[G[p.second][i].first]>color[p.second]+G[p.second][i].second) {
                color[G[p.second][i].first]=color[p.second]+G[p.second][i].second;
                PQ.push(make_pair(color[G[p.second][i].first],G[p.second][i].first));
            }
        }
    }
    for(int i=0;i<N;i++) {
        ans[i] = color[i];
    }
}

signed main(){
    cin >> N;
    G.resize(N);
    ans.resize(N);
    for(int i=0;i<N-1;i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,c));
    }
    cin >> Q >> K;
    K--;
    //cout << "OK" << endl;
    dijkstra(K);
    //cout << "OK" << endl;
    for(int i=0;i<Q;i++) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        cout << ans[x]+ans[y] << endl;
    }
    return 0;
}