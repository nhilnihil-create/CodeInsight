#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int count_digits(ll n) {
    int digits = 0;
    while (n > 0) {
        n /= 10;
        ++digits;
    }
    return digits;
}

int main() {

    ll N;
    cin >> N;

    int ans = count_digits(N);
    for (ll a = 1LL; a*a <= N; ++a) {
        if (N%a != 0) continue;
        ll b = N / a;
        int c = max(count_digits(a), count_digits(b));
        ans = min(ans, c);
    }

    cout << ans << endl;

    return 0;
}