#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

void dfs(int i,vector<vector<int>>& edges,vector<bool>& used,vector<int>& ret) {
    for (int j : edges[i]) if (!used[j]) {
        used[j] = true;
        ret.push_back(j);
        dfs(j,edges,used,ret);
        break;
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> ans;
    vector<bool> used(n,false);
    vector<vector<int>> edges(n);
    for (int i = 0;i < m;++i) {
        int u,v;
        cin >> u >> v;
        u--;v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    ans.push_back(0);
    used[0] = true;
    dfs(0,edges,used,ans);
    reverse(ans.begin(),ans.end());
    dfs(0,edges,used,ans);
    cout << ans.size() << endl;
    for (int i = 0;i < ans.size();++i)  cout << ans[i]+1 << " \n"[i == ans.size()-1];
    return 0;
}