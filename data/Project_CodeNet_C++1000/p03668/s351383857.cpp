#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

vector<vector<int>> edges;

int dfs(int i,int p = -1) {
    int g = 0;
    for (int& j : edges[i]) if (j != p) {
        g ^= dfs(j,i)+1;
    }
    return g;
}

int main() {
    int n;
    cin >> n;
    edges.resize(n);
    for (int i = 0;i < n-1;++i) {
        int u,v;
        cin >> u >> v;
        u--;v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cout << (dfs(0) ? "Alice" : "Bob") << endl;
    return 0;
}