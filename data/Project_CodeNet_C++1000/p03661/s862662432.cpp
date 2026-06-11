#include <bits/stdc++.h>
#define mp make_pair
#define all(vec) vec.begin(), vec.end()
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = 1LL << 30;
const ll LINF = 1LL << 60;
const double eps = 1e-9;
const ll MOD = 1000000007LL;
template <typename T>
void chmin(T& a, T b) {
    a = min(a, b);
};
template <typename T>
void chmax(T& a, T b) {
    a = max(a, b);
};
template <typename T>
vector<T> make_v(size_t a) {
    return vector<T>(a);
}
template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type fill_v(T& t, const V& v) {
    t = v;
}
template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type fill_v(T& t, const V& v) {
    for(auto& e : t) {
        fill_v(e, v);
    }
};
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ll s = 0;
    ll ans = LINF;
    for(int i = 0; i < n - 1; i++) {
        s += a[i];
        chmin(ans, abs(s - (sum - s)));
    }
    cout << ans << endl;
}
