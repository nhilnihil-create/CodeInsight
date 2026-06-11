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

ll calcDigit(ll n) {
    ll d = 1;
    while (n >= 10) {
        n /= 10;
        d++;
    }
    return d;
}
int main() {
    ll N;
    cin >> N;

    vector<pair<ll, ll> > pairs;
    ll ans = INF;
    for (ll i = 1; i * i <= N; ++i) {
        if ((N % i) == 0) {
            ll a = calcDigit(i);
            ll b = calcDigit(N / i);
            chmin(ans, max(a, b));
        }
    }

    cout << ans << endl;

    return 0;
}