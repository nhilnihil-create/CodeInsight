#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
#define debug(x) cerr << #x << ": " << x << '\n'
using namespace std;
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

using ll = long long;
using ull = unsigned long long;
const int INF = 1e9;
// const int MOD = 1e9 + 7;

using P = pair<ll, ll>;
int main() {
    ll N, T;
    cin >> N >> T;
    vector<ll> t(N);
    for (int i = 0; i < N; i++) {
        cin >> t.at(i);
    }
    ll ans = 0;
    ll s = 0, g = 0;
    for (int i = 0; i < N; i++) {
        if (t[i] <= g) {
            g = t[i] + T;
        } else {
            ans += g - s;
            s = t[i];
            g = t[i] + T;
        }
    }
    ans += g - s;
    cout << ans << endl;
}
