#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
using ll = long long;

int digits(ll n) {
    int cnt = 0;
    while (n) {
        cnt++;
        n /= 10;
    }
    return cnt;
}

int main() {
    ll N;
    cin >> N;
    ll ans = (1 << 20);
    for (ll i = 1; i * i <= N; i++) {
        if (N % i != 0) continue;
        ans = min(ans, (ll)max(digits(i), digits(N / i)));
    }
    cout << ans << endl;
}