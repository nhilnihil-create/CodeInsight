#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

#define MAX 100000

vector<int> G[MAX];

int rec(int cur) {
    if (G[cur].empty()) {
        return 0;
    }
    vector<int> v;
    for (int to : G[cur]) {
        v.emplace_back(rec(to));
    }
    sort(ALL(v));
    reverse(ALL(v));
    int res = v.size();
    for (int i = 0; i < (int)v.size(); i++) {
        res = max(res, v[i] + i);
    }
    res++;
    return res;
}

signed main() {
    int n;
    cin >> n;
    int a;
    for (int i = 1; i < n; i++) {
        cin >> a;
        a--;
        G[a].emplace_back(i);
    }
    cout << rec(0) - 1 << endl;
    return 0;
}