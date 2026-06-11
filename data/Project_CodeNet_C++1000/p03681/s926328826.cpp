#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    int N, M;
    cin >> N >> M;

    if (abs(N - M) >= 2) {
        cout << 0 << endl;
        return 0;
    }

    const ll MOD = 1000000007;
    const ll MAX = 100005;

    vl fac(MAX);
    fac[0] = 1;
    fac[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = i * fac[i - 1] % MOD;
    }

    ll x = (fac[N] * fac[M]) % MOD;
    if (x < 0) x += MOD;
    if (N == M) {
        // N! * M! * 2
        ll y = (x * 2) % MOD;
        if (y < 0) y += MOD;
        cout << y << endl;
    } else {
        // N! * M!
        cout << x << endl;
    }
}