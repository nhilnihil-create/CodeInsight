#include <bits/stdc++.h>

using namespace std;

template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

int n;
VV<int> g;

int dfs(int v) {
    V<int> st;
    for (int u: g[v]) {
        st.push_back(dfs(u));
    }
    sort(st.begin(), st.end());
    int g = 0;
    for (int d: st) {
        g = max(g, d) + 1;
    }
    return g;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    g = VV<int>(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p; p--;
        g[p].push_back(i);
    }
    cout << dfs(0) << "\n";
    return 0;
}
