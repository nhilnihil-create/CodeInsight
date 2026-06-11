#include <bits/stdc++.h>
using namespace std;
template<typename T> inline bool chmax(T& a,T b) { if (a < b) { a = b; return true; } return false; }
template<typename T> inline bool chmin(T& a,T b) { if (a > b) { a = b; return true; } return false; }
constexpr long long INF = 1e18;

int main() {
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    for (auto& e : a) cin >> e;
    
    vector<vector<long long>> cost(n, vector<long long>(n));
    for (int i = 0; i < n; i++) cost[i][0] = a[i];
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n; i++) {
            cost[(i+1)%n][j] = cost[i][j-1];
        }
    }
    
    auto f = [&] (int k) {
        long long res = k * x;
        for (int i = 0; i < n; i++) {
            long long c = INF;
            for (int j = 0; j <= k; j++) chmin(c, cost[i][j]);
            res += c;
        }
        return res;
    };
    
    int l = 0, r = n-1;
    while (abs(l - r) > 2) {
        int m1 = (l * 2 + r) / 3;
        int m2 = (l + r * 2) / 3;
        if (f(m1) > f(m2)) l = m1;
        else r = m2;
    }
    
    long long ans = INF;
    for (int i = l; i <= r; i++) chmin(ans, f(i));
    cout << ans << endl;
    return 0;
}