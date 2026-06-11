#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> g[110000];
vector<int> pt;
int tam[110000];

bool dfsf(int v, int p) {
    pt.push_back(v);

    if (v == n-1) return true;
    for (int x : g[v]) if (x != p) {
        if (dfsf(x, v)) return true;
    }

    pt.pop_back();
    return false;
}

int dfsz(int v, int p) {
    tam[v]=1;
    for (int x : g[v]) if (x != p) tam[v] += dfsz(x,v);
    return tam[v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u,v; cin >> u >> v; u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfsf(0,-1);
    dfsz(0,-1);

    int len = pt.size();

    int idx_fen = (len-1)/2;
    int has_fen = tam[pt[idx_fen]];
    int has_snu = tam[pt[idx_fen+1]];

    if (has_fen > has_snu) has_fen = n - has_snu;
    else has_snu = n - has_fen;

    if (has_fen > has_snu) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
    return 0;
}