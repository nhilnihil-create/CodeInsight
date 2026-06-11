#include <bits/stdc++.h>

using namespace std;

static long long MOD = 1e9 + 7;

/*
 * 素因数とその個数の map を返す
 */
static map<long long, long long> calc_prime_factor (long long n) {
    map<long long, long long> prime_factor;
    for ( long long i = 2; i * i <= n; i++ ) {
        while ( n % i == 0 ) {
            prime_factor[i]++;
            n /= i;
        }
    }
    if ( n != 1 )
        prime_factor[n]++;
    return prime_factor;
}

int main (void) {
    int N;
    cin >> N;

    map<long long, long long> prime_factor;
    vector<long long> n_factor(N+1, 0);
    for ( int i = 2; i <= N; i++ ) {
        prime_factor = calc_prime_factor(i);
        for ( auto itr : prime_factor )
            n_factor[itr.first] += itr.second;
    }

    long long ans = 1;
    for ( int i = 2; i <= N; i++ ) {
        ans *= n_factor[i] + 1;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}
