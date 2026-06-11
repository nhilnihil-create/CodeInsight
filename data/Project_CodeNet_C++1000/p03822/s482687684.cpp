#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

vector<vector<int>> edges;
vector<int> dp;

void dfs(int i) {
    if (edges[i].size() == 0) return;
    for (int j : edges[i]) dfs(j);
    vector<int> a;
    for (int j : edges[i]) a.push_back(dp[j]);
    sort(a.begin(),a.end(),greater<int>());
    for (int j = 0;j < a.size();++j) a[j] += j+1;
    dp[i] = *max_element(a.begin(),a.end());
}

int main() {
    int n;
    cin >> n;
    edges.resize(n);
    dp = vector<int>(n,0);
    for (int i = 1;i < n;++i) {
        int a;
        cin >> a;--a;
        edges[a].push_back(i);
    }
    dfs(0);
    cout << dp[0] << endl;
    return 0;
}