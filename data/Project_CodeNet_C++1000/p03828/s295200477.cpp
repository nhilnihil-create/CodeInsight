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
vector<ll> getNums(ll N) {
    vector<ll> num(N);
    REP(i, N) {
        cin >> num[i];
    }
    return num;
}

unordered_map<ll, ll> values;

void func(ll n) {
    for (ll i = 2; i * i <= n; ++i) {
        while ((n % i) == 0) {
            n /= i;
            values[i]++;
        }
    }
    if (n != 1) {
        values[n]++;
    }
}
int main() {
    ll N;
    cin >> N;
    values.clear();
    for (ll i = 1; i <= N; ++i) {
        func(i);
    }

    ll ans = 1;
    for (const auto& v : values) {
        ans *= v.second + 1;
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}