#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<int> to[2505];
vector<int> rto[2505];
const ll INF = 1e18;
bool reachableFrom1[2505];
bool reachableToN[2505];
bool ok[2505];
void dfs(int v) {
    if (reachableFrom1[v]) return;
    reachableFrom1[v] = true;
    for (int u : to[v]) {
        dfs(u);
    }
}
void rdfs(int v) {
    if (reachableToN[v]) return;
    reachableToN[v] = true;
    for (int u : rto[v]) {
        rdfs(u);
    }
}
int main() {
    int n, m; cin >> n >> m;
    vector<tuple<int,int,int>> edges;
    rep(i, m) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--; c = -c;
        edges.emplace_back(a, b, c);
        to[a].push_back(b);
        rto[b].push_back(a);
    }
    dfs(0); rdfs(n-1);
    rep(i, n) ok[i] = reachableFrom1[i]&reachableToN[i];
    {//Bellman-Ford
        vector<ll> d(n, INF);
        d[0] = 0;
        bool upd = true;
        int step = 0;
        while(upd) {
            upd = false;
            rep(i,m) {
                int a, b, c;
                tie(a,b,c) = edges[i];
                if(!ok[a]) continue;
                if(!ok[b]) continue;
                ll newD = (ll)(d[a] + c);
                if(newD < d[b]) {
                    upd = true;
                    d[b] = newD;
                }
            }
            step++;
            if(step > n){
                puts("inf");
                return 0;
            }
        }
        ll ans = -d[n-1];
        //ans = max(ans, 0ll);
        cout << ans << endl;
    }
}
