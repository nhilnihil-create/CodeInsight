#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

vector<int> dist(100010),edges[100010];
int ans = 0,d = 0;

int dfs(int i,int k) {
    int d = 0;
    for (int& j : edges[i]) d = max(d,dfs(j,k)+1);
    if (d == k-1 && dist[i] != 1 && i) {
        d = -1;
        ans++;
    }
    return d;
}

int main() {
    int n,k;
    cin >> n >> k;
    int a;
    cin >> a;
    if (a != 1) ans++;
    for (int i = 1;i < n;++i) {
        cin >> a;
        edges[a-1].push_back(i);
        if (a == 1) dist[i] = 1;
    }
    dfs(0,k);
    cout << ans << endl;
}