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
const ll INF = 1e18;
// const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    ll ans = INF;
    ll sum = 0;
    ll tmp = 0;
    for (int i = 0; i < N; i++) {
        sum += a[i];
        if (i % 2 == 0) {
            ll add = max(1LL - sum, 0LL);
            sum += add;
            tmp += add;
        } else {
            ll sub = min(-1LL - sum, 0LL);
            sum += sub;
            tmp -= sub;
        }
    }
    chmin(ans, tmp);

    sum = 0;
    tmp = 0;
    for (int i = 0; i < N; i++) {
        sum += a[i];
        if (i % 2 == 1) {
            ll add = max(1LL - sum, 0LL);
            sum += add;
            tmp += add;
        } else {
            ll sub = min(-1LL - sum, 0LL);
            sum += sub;
            tmp -= sub;
        }
    }
    chmin(ans, tmp);

    cout << ans << endl;
}
