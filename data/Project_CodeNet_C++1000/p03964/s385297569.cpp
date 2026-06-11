#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int N;
    cin >> N;

    ll prev_a, prev_b;
    cin >> prev_a >> prev_b;
    ll ans = prev_a + prev_b;
    rep(i, N - 1) {
        long double a, b;
        cin >> a >> b;
        ll m = max(ceil(prev_a / a), ceil(prev_b / b));
        a *= m, b *= m;

        ans = a + b;
        prev_a = a, prev_b = b;
    }

    cout << ans << endl;
}