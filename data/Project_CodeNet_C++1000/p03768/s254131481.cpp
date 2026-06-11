#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    int n,m,q;
    cin >> n >> m;
    vector<int> color(n,0),dist(n,-1);
    vector<vector<int>> edges(n);
    for (int i = 0;i < m;++i) {
        int u,v;
        cin >> u >> v;
        u--;v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cin >> q;
    vector<int> v(q),d(q),c(q);
    for (int i = 0;i < q;++i) cin >> v[i] >> d[i] >> c[i];
    for (int i = q-1;i >= 0;--i) {
        v[i]--;
        stack<int> st;
        if (color[v[i]] == 0) color[v[i]] = c[i];
        if (dist[v[i]] < d[i]) {
            st.push(v[i]);
            dist[v[i]] = d[i];
        }
        while (!st.empty()) {
            int t = st.top();
            st.pop();
            if (color[t] == 0) color[t] = c[i];
            if (dist[t] != 0) for (int j : edges[t]) {
                if (dist[j] < dist[t]-1) {
                    dist[j] = dist[t]-1;
                    st.push(j);
                }
            }
        }
    }
    for (int i : color) printf("%d\n", i);
    return 0;
}