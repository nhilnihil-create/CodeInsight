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

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N), BIG;
    rep(i, N) cin >> A[i];

    ll check = A[0];
    sort(A.begin(), A.end());
    rep(i, N) { check = gcd(A[i], check); }
    rep(i, N) {
        if (A[i] >= K) BIG.push_back(A[i] - K);
    }

    bool ans = false;
    rep(i, BIG.size()) {
        if (BIG[i] % check == 0) ans = true;
    }

    if (ans)
        cout << "POSSIBLE\n";
    else
        cout << "IMPOSSIBLE\n";

    return 0;
}