#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    int n,m;
    cin >> n >> m;
    int ans = n;
    vector<bool> use(m,true);
    vector<vector<int>> a(n,vector<int>(m));
    for (int i = 0;i < n;++i) for (int j = 0;j < m;++j) cin >> a[i][j],a[i][j]--;
    for (int z = 0;z < m;++z) {
        vector<int> b(m,0);
        for (int i = 0;i < n;++i) for (int j = 0;j < m;++j) if (use[a[i][j]]) {
            b[a[i][j]]++;
            break;
        }
        int idx = 0;
        for (int i = 0;i < m;++i) if (b[i] > b[idx]) idx = i;
        ans = min(ans,b[idx]);
        use[idx] = false;
    }
    cout << ans << endl;
}