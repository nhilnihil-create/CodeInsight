#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
#define int ll

int n, q, k;
vector<vector<pll>> G;
int dis[100010];

void dfs(int v, int p, int d){
    dis[v] = d;
    for(auto nv : G[v]){
        if(nv.first == p) continue;

        dfs(nv.first, v, d + nv.second);
    }
}

signed main(){
    cin >> n;
    G.resize(n);
    int a, b, c;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back(pii(b, c));
        G[b].push_back(pii(a, c));
    }
    cin >> q >> k;
    k--;
    dfs(k, -1, 0);

    vector<int> x(q), y(q);
    for (int i = 0; i < q; ++i) {
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }

    for (int i = 0; i < q; ++i) {
        cout << dis[x[i]] + dis[y[i]] << endl;
    }
}