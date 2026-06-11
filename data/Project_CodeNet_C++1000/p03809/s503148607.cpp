#include <numeric>
#include <functional>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> adj[n];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    function<long long(int, int)> dp = [&](int i, int p) {
        vector<long long> v;
        for (int j : adj[i]) {
            if (j != p) v.push_back(dp(j, i));
        }
        if (v.empty()) return (long long)a[i];
        sort(v.begin(), v.end());
        long long s = accumulate(v.begin(), v.end(), 0LL);
        long long x = s - a[i];
        if (0 <= x && x <= s / 2 && x <= s - v.back()) return 2 * a[i] - s;
        else throw exception();
    };
    try {
        long long r = dp(0, -1);
        cout << (r == 0 || adj[0].size() == 1 ? "YES\n" : "NO\n");
    } catch (exception &e) {
        cout << "NO\n";
    }
}
