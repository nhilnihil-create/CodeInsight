#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int n, t[200005];

void inc(int l, int r) {
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) t[l++]++;
        if (r & 1) t[--r]++;
    }
}

int que(int x) {
    int z = 0;
    for (x += n; x; x >>= 1) z += t[x];
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    int m, u, v, c = 0;
    vector<pii> a[100005] = {};
    cin >> m >> n; c = m; n++;
    while (m--) cin >> u >> v, a[v - u + 1].push_back({u, v + 1});
    for (int i = 1; i < n; i++) {
        int z = 0;
        for (int j = i; j <= n; j += i) z += que(j);
        cout << z + c << '\n';
        for (pii j : a[i]) inc(j.first, j.second), c--;
    }
}
