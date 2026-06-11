#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)


int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    vector<P> color(n,P(-1,-1));
    for (int i = 0;i < m;++i) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int q;
    cin >> q;
    vector<int> v(q),d(q),c(q);
    for (int i = 0;i < q;++i) {
        cin >> v[i] >> d[i] >> c[i];
        v[i]--;
    }
    for (int i = q-1;i >= 0;--i) {
        if (color[v[i]].second >= d[i]) continue;
        vector<P> que;
        que.push_back(P(v[i],d[i]));
        while (!que.empty()){
            P p = que.back();que.pop_back();
            if (color[p.first].first < 0) color[p.first] = P(i,p.second);
            if (p.second < 1) continue;
            for (int j : edges[p.first]) {
                if (color[j].second < p.second-1) {
                    que.push_back(P(j,p.second-1));
                    color[j].second = p.second-1;
                }
            }
        }
    }
    for (int i = 0;i < n;++i) {
        int j = color[i].first;
        cout << (j > -1 ? c[j] : 0) << endl;
    }
    return 0;
}