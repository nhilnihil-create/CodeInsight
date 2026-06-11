#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using vint = vector<int>;
using vll = vector<ll>;
template<typename T> using uset = unordered_set<T>;
template<typename T1, typename T2> using umap = unordered_map<T1, T2>;

constexpr int INF = (1 << 30) - 1;
constexpr ll LLINF = 1LL << 60;
constexpr int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
constexpr int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr char el = '\n';
constexpr int mod = 1000000007;

template<typename T> T gcd(T a, T b) { return (b ? gcd(b, a % b) : a); }
template<typename T> T lcm(T a, T b) { return (a / gcd(a, b) * b); }
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

ll N, L, T;
ll X[100005], W[100005];
vll xp, xn;
ll ans[100005] = {};
int main() {
    cin >> N >> L >> T;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> W[i];
        (W[i] == 1 ? xp : xn).push_back(X[i]);
        (W[i] == 1 ? xp : xn).push_back(X[i] + L);
    }
    sort(begin(xp), end(xp));
    sort(begin(xn), end(xn));

    for (int i = 0; i < N; i++) {
        ll t = T * 2 % L;
        if (W[i] == 1) {
            ll num = lower_bound(begin(xn), end(xn), X[i] + t) - lower_bound(begin(xn), end(xn), X[i]);
            num += (T * 2 / L) * (xn.size() / 2);
            ans[(i + num) % N] = (X[i] + T) % L;
        } else {
            ll num = --upper_bound(begin(xp), end(xp), X[i] + L) - --upper_bound(begin(xp), end(xp), X[i] + L - t);
            num += (T * 2 / L) * (xp.size() / 2);
            ans[(i + N - num % N) % N] = (X[i] + L - T % L) % L;
        } 
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << el;
    }
    return (0);
}
