#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
const long long INF = numeric_limits<long long>::max();
int main() {
    ll N, T;
    cin >> N >> T;

    vector<ll> times(N);
    for (ll i = 0; i < N; ++i) {
        cin >> times[i];
    }

    ll sum = T;
    for (ll i = 0; i < N - 1; ++i) {
        ll next = times[i] + T;
        if (next > times[i + 1]) {
            sum += T - (next - times[i + 1]);
        } else {
            sum += T;
        }
    }
    cout << sum << endl;

    return 0;
}