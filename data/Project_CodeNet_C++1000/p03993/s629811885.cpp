#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    int ans = 0;
    vector<int> flag(N, 1);
    for (int i = 0; i < N; ++i) {
        if (a[i] == a[a[a[i] - 1] - 1] && flag[a[i] - 1]) {
            flag[a[i] - 1] = 0;
            ans += 1;
        }
    }
    cout << ans/2 << endl;
    return 0;
}