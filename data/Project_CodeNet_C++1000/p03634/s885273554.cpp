#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

#define MAX_V 100010

struct edge { int to; ll cost; };
int V;

vector<edge> tree[MAX_V];
long long d[MAX_V];
int N;

// s: 開始地点の頂点
void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d + N, LINF);
    d[s] = 0;
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) { continue; }
        for (int i = 0; i < tree[v].size(); i++) {
            edge e = tree[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}


int main(){
    cin >> N;

    rep(i, N - 1){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--, b--;
        tree[a].push_back(edge{b, c});
        tree[b].push_back(edge{a, c});
    }

    int Q, K;
    cin >> Q >> K;
    vector<ll> ans;

    dijkstra(K-1);

    rep(i, Q){
        int x, y;
        cin >> x >> y;
        x--, y--;
        ans.push_back(d[x] + d[y]);
    }

    rep(i, Q) cout << ans[i] << endl;

    return 0;
}