#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    ll N, M;
    cin >> N >> M;

    if(abs(N-M) >= 2) {
        cout << 0 << endl;
        return 0;
    }
    ll a = 1, b=1;

    for(int i=2; i <= N; i++) {
        a *= i;
        a %= (ll)(1e9 + 7);
    }
    for(int i=2; i <= M; i++) {
        b *= i;
        b %= (ll)(1e9 + 7);
    }
    ll ans = (a * b) % (ll)(1e9 + 7);
    if (N == M) ans *= 2;
    ans %= (ll)(1e9 + 7);
    cout << ans << endl;

}