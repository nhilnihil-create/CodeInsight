#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

void dfs(int i,vector<vector<int>>& a,vector<int>& depth) {
    for (int j : a[i]) dfs(j,a,depth);
    vector<int> b;
    for (int j : a[i]) b.push_back(depth[j]);
    sort(b.begin(),b.end(),greater<int>());
    for (int j = 0;j < a[i].size();++j) depth[i] = max(depth[i],b[j]+j+1);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    vector<int> depth(n,0);
    for (int i = 1;i < n;++i) {
        int b;
        cin >> b;
        b--;
        a[b].push_back(i);
    }
    //for (int i = 0;i < n;++i) p_ary(a[i],0,a[i].size(),j);
    dfs(0,a,depth);
    //p_ary(depth,0,n,i);
    cout << depth[0] << endl;
    return 0;
}