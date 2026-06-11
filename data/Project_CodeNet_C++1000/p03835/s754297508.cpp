#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
const long long INF = numeric_limits<long long>::max();
template <class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main() {
    ll K, S;
    cin >> K >> S;

    ll count = 0;
    for (ll x = 0; x <= K; ++x) {
        for (ll y = 0; y <= K; ++y) {
            ll z = S - (x + y);
            if (z < 0) continue;
            if (z > K) continue;
            count++;
        }
    }

    cout << count << endl;

    return 0;
}