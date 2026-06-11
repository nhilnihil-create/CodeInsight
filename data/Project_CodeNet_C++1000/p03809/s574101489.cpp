#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

vector<ll> a;
vector<vector<int>> edges;

ll dfs(int i,int p) {
    ll sum = 0,mx = 0;
    for (int j : edges[i]) if (j != p) {
        ll c = dfs(j,i);
        if (c == -1) return -1;
        sum += c;
        if (mx < c) mx = c;
    }
    if (edges[i].size() == 1) return a[i];
    if (sum < a[i] || mx > a[i] || sum > 2*a[i]) return -1;
    return 2*a[i]-sum;
}

int main() {
    int n;
    cin >> n;
    a.resize(n);
    edges.resize(n);
    for (int i = 0;i < n;++i) cin >> a[i];
    for (int i = 0;i < n-1;++i) {
        int u,v;
        cin >> u >> v;
        u--;v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    ll m = -1;
    for (int i = 0;i < n;++i) if (edges[i].size() > 1) {
        m = dfs(i,-1);
        break;
    }
    if (n == 2 && a[0] == a[1]) m = 0;
    cout << (m == 0 ? "YES" : "NO") << endl;
    return 0;
}