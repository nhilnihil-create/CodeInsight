#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;
// ------------------------------

int main() {
    ll N, K;
    cin >> N >> K;
    vector<pair<int, int>> vec(N);
    rep(i, N) {
        cin >> vec[i].first >> vec[i].second;
    }
    sort(ALL(vec));
    int idx = 0;
    int ans = 0;
    while (K > 0) {
        ans = vec[idx].first;
        K -= vec[idx].second;
        idx += 1;
    }
    cout << ans << endl;
    return 0;
}