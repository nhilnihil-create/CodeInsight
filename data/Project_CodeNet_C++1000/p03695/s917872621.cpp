#include <bits/stdc++.h>
using namespace std;
using ll         = int;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
const long long INF = numeric_limits<long long>::max();
int main() {
    ll N;
    cin >> N;
    ll free = 0;
    vector<ll> rank(8, 0);
    for (ll i = 0; i < N; ++i) {
        ll n;
        cin >> n;
        if (n >= 3200) {
            free++;
        } else {
            rank[n / 400]++;
        }
#ifdef SOURCE_TEST

        cout << n << ":" << n / 400 << endl;
#endif
    }

    ll sum = 0;
    for (ll i = 0; i < rank.size(); ++i) {
        sum += (rank[i] > 0) ? 1 : 0;
    }
    cout << (max(sum, 1)) << " " << sum + free << "\n";
    return 0;
}