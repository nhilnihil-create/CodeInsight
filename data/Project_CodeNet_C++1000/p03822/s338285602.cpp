#include <bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i = m; i < (int)(n); ++i)
#define rep(i,n) REP(i, 0, n)

vector<int> children[100010];

int dfs(int par) {
    if (children[par].empty()) return 0;
    vector<int> v;
    for (auto ch : children[par]) {
        v.push_back(dfs(ch) + 1);
    }
    sort(v.begin(), v.end());
    REP(i, 1, v.size()) {
        if (v[i - 1] >= v[i]) v[i] = v[i - 1] + 1;
    }
    return *v.rbegin();
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int par;
        cin >> par;
        children[par].push_back(i);
    }
    cout << dfs(1) << endl;
    return 0;
}