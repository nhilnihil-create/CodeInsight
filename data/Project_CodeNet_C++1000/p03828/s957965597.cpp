#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
#define PR(x) cout << (x) << "\n"
#define PS(x) cout << (x) << " "
const long long INF = numeric_limits<long long>::max();
map<ll, ll> Factorization(ll N) {
    map<ll, ll> values;
    for (ll i = 2; i * i <= N; ++i) {
        while ((N % i) == 0) {
            values[i]++;
            N /= i;
        }
    }
    if (N != 1) {
        values[N]++;
    }
    return values;
}
int main() {
    ll N;
    cin >> N;

    map<ll, ll> values;
    REP2(i, 1, N + 1) {
        auto vs = Factorization(i);
        for (const auto& v : vs) {
            values[v.first] += v.second;
#ifdef SOURCE_TEST
            cout << v.first << ":" << v.second << endl;
#endif
        }
    }
    ll count = 1;
    for (const auto& v : values) {
        count *= v.second + 1;
        count %= MOD;
    }

    PR(count);

    return 0;
}