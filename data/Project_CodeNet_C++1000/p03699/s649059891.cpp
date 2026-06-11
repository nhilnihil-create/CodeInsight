#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> s(n);
    ll sum = 0, mini = INF;
    rep(i, n) {
        cin >> s[i];
        sum += s[i];
    }

    sort(s.begin(), s.end());
    rep(i, n) {
        if (s[i] % 10 != 0) {
            mini = s[i];
            break;
        }
    }

    if (sum % 10 == 0 && mini != INF) {
        cout << sum - mini << "\n";
    } else if (mini != INF) {
        cout << sum << "\n";
    } else {
        cout << 0 << "\n";
    }
    return 0;
}