#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    int N, T;
    cin >> N >> T;
    ll ans = 0;
    vector<int> t(N);
    rep(i, N) cin >> t[i];
    ans = T*t.size();
    FOR(i, 1, N) {
        if (t[i] - t[i - 1] < T) {
            ans -= T - t[i] + t[i - 1];
        }
    }
    cout << ans << endl;
    return 0;
}