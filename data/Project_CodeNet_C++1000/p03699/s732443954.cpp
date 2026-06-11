#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
const long long INF = numeric_limits<long long>::max();
int main() {
    ll N;
    cin >> N;

    vector<ll> scores(N);
    ll sum = 0;
    for (ll i = 0; i < N; ++i) {
        cin >> scores[i];
        sum += scores[i];
    }

    sort(scores.begin(), scores.end());
    if (sum % 10 == 0) {
        for (ll i = 0; i < N; ++i) {
            if (scores[i] % 10 != 0) {
                sum -= scores[i];
                break;
            }
        }
    }

    if (sum % 10 != 0) {
        cout << sum << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}