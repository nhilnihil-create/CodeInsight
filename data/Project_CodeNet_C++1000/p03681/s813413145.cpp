#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;

const ll MOD = 1E+9 + 7;

int main() {
    ll N, M;
    cin >> N >> M;

    ll ans;
    if (abs(N - M) > 1) ans = 0;
    else {
        ans = 1;
        for (int n=N; n>=1; n--) {
            ans *= n;
            ans %= MOD;
        }
        for (int m=M; m>=1; m--) {
            ans *= m;
            ans %= MOD;
        }
        if (M == N) {
            ans *= 2;
            ans %= MOD;
        }
    }

    cout << ans << endl;

    return 0;
}