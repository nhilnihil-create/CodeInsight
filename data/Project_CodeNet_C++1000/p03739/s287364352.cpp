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

vector<ll> vec;
ll N;
ll func(ll s) {
    ll c   = 0;
    ll sum = 0;
    for (ll i = 0; i < N; ++i) {
        bool isSign = (i % 2) == s;
        ll tmp      = sum + vec[i];
        if (isSign != (tmp > 0) || tmp == 0) {
            ll next = isSign ? 1 : -1;
            c += abs(tmp - next);
#ifdef SOURCE_TEST
            cout << sum << ":" << tmp << endl;
#endif

            sum = next;
        } else {
            sum = tmp;
        }
    }
    return c;
}
int main() {
    cin >> N;
    vec.resize(N);
    REP(i, N) {
        cin >> vec[i];
    }

#ifdef SOURCE_TEST

    for (auto v : vec) {
        cout << v << ",";
    }
    cout << endl;

#endif
    ll count = min(func(0), func(1));

    cout << count << endl;
    return 0;
}