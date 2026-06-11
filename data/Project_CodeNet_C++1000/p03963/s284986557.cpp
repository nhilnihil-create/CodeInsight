#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int N, K;
    cin >> N >> K;

    ll ans = K;
    rep(i, N - 1) {
        ans *= K - 1;
    }

    cout << ans << endl;

    return 0;
}