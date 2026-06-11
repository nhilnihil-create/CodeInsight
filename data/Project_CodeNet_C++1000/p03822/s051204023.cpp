#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < int(n); i++)
#define FOR(i,n,m) for(int i = int(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 1e18 + 1;

int n;

int f(int v, int par, const vector<vector<int>> &G) {
    vector<int> vec;
    for (int u : G[v]) {
        if (u == par) continue;
        vec.push_back(f(u, v, G));
    }
    if (vec.size() == 0) return 0;
    sort(vec.rbegin(), vec.rend());
    int res = 0;
    int m = vec[0] + 1;
    REP(i, vec.size()) {
        m = max(m,vec[i] + i + 1);
    }
    res = m;
    return res;
}

int main() {
    cin >> n;
    vector<vector<int>> G(n);
    REP(i,n-1) {
        int a; cin >> a;
        G[i+1].push_back(a - 1);
        G[a-1].push_back(i+1);
    }
    cout << f(0,-1, G) << endl;
    return 0;
}