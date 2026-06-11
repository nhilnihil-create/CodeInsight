#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<P>>;
 
int main() {
    int N;
    cin >> N;
    Graph G(N);
    rep(i, N-1) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back(P(b, c));
        G[b].push_back(P(a, c));
    }
    int Q, K;
    cin >> Q >> K;
    K--;
    vector<int> x(Q), y(Q);
    rep(i, Q) {
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }
 
    vector<ll> dist(N, -1);
    queue<int> que;
    dist[K] = 0;
    que.push(K);
 
    while (!que.empty()) {
        int v = que.front(); que.pop();
 
        for (P nv: G[v]) {
            if (dist[nv.first] != -1) continue;
            dist[nv.first] = dist[v] + nv.second;
            que.push(nv.first);
        }
    }
    
    rep(i, Q) {
        cout << dist[x[i]] + dist[y[i]] << endl;
    }
    return 0;
}