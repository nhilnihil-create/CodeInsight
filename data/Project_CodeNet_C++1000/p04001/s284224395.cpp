#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;
// ------------------------------

int main() {
    string S;
    cin >> S;
    ll ans = 0;
    int N = S.size();
    for (int bit = 0; bit < (1 << N); ++bit) {
        ll tmp = 0;
        rep(i, N) {
            if (bit & (1 << i)) {
                ans += tmp;
                tmp = 0;
            } else {
                tmp = tmp*10 + (int)(S[i] - '0');
            }
        }
        ans += tmp;
    }
    cout << ans << endl;
    return 0;
}