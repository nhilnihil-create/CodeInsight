#include <bits/stdc++.h>

using namespace std;

static long long MOD = 1e9 + 7;

long long calc_perm (long long n, long long r) {
    long long ret = 1;
    for ( int i = 0; i < r; i++ ) {
        ret *= n;
        ret %= MOD;
        n--;
    }
    return ret;
}

int main (void) {
    int N, M;
    cin >> N >> M;

    if ( abs(N - M) > 1 ) {
        cout << 0 << endl;
        return 0;
    }

    long long n_perm = calc_perm(N, N);
    long long m_perm = calc_perm(M, M);
    long long ans = (n_perm * m_perm) % MOD;
    if ( abs(N - M) != 1 )
        ans = (2 * ans) % MOD;

    cout << ans << endl;
    return 0;
}
