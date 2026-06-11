#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, M, ans=0, tmp=0, state=0;
deque<ll> Q;
vector<vector<ll>> G;

signed main(){
    cin >> N >> M;
    G.resize(N);
    vector<ll> used(N);
    for(int i=0;i<M;i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
        if(i==0) {
            Q.push_front(a);
            Q.push_back(b);
            used[a] = true;
            used[b] = true;
        }
    }
    while (true) {
        bool update = false;
        int u = Q.front();
        for (int i = 0; i < G[u].size(); i++) {
            int to = G[u][i];
            if (used[to]) continue;
            used[to] = true;
            update = true;
            Q.push_front(to);
            break;
        }
        int v = Q.back();
        for (int i = 0; i < G[v].size(); i++) {
            int to = G[v][i];
            if (used[to]) continue;
            used[to] = true;
            update = true;
            Q.push_back(to);
            break;
        }
        if (!update) break;
    }
 
    cout << Q.size() << endl;
    for(int i = 0;i<Q.size();i++) cout << Q[i]  + 1 << " ";
 
    return 0;
}