#include<iostream>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, X;
    cin >> N >> X;
    ll ans = X;
    ll d = N - X;
    ll cnt = N / d;
    ans += 2 * d * cnt - d;
    ll tmp = d;
    if (N % d == 0) ans -= d;
    d = N % d;
    N = tmp;
    while (d > 0) {
        cnt = N / d;
        ans += 2 * d * cnt;
        tmp = d;
        if (N % d == 0) {
            ans -= d;
        }
        d = N % d;
        N = tmp;
    }
    cout << ans << endl;
    return 0;
}