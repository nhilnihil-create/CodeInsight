#include <bits/stdc++.h>
using namespace std;
#define Int int64_t
#define dump(x) cout << (x) << endl
#define fi first
#define se second
Int mod = 1e9+7;
//Int mod = 998244353;
Int INF = 1e18;
double EPS = 0.00000001;

Int n;
vector<Int> G[100001];
 
Int dfs(Int x) {
    //cout << "pro" << " " << x << endl;
    if (G[x].empty()) {
        return 0;
    }
    vector<Int> v;
    for (Int i = 0; i < (Int)G[x].size(); i++) {
        v.push_back(dfs(G[x][i]));
    }
    Int ma = -1;
    sort(v.begin(), v.end(), greater<Int>());
    for (Int i = 0; i < (Int)v.size(); i++) {
        ma = max(ma, v[i] + i + 1);
    }
    //cout << x << " " << ma << endl;
    return ma;
}

int main() {
    cin >> n;
    for (Int i = 2; i <= n; i++) {
        Int x;
        cin >> x;
        G[x].push_back(i);
    }
    dump(dfs(1));
    return 0;
}