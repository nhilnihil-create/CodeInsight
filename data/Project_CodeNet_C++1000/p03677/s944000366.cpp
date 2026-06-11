#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
template <typename X, typename Y> istream& operator>>(istream& is, pair<X, Y>& p) { return is >> p.first >> p.second; }
void solve(long long n, long long m, std::vector<long long> a) {
    ll base_cost = 0;
    vector<ll> saved(2 * m + 3);
    auto update = [&](int L, int R) {
        saved[L + 1] += 1;
        saved[R + 1] -= R - L + 1;
        saved[R + 2] += R - L;
    };
    for(int i = 1; i < n; i++) {
        base_cost += (a[i] - a[i - 1] + m) % m;
        a[i] > a[i - 1] ? update(a[i - 1] + 1, a[i]) : update(a[i - 1] + 1, a[i] + m);
    }
    partial_sum(saved.begin(), saved.end(), saved.begin());
    partial_sum(saved.begin(), saved.end(), saved.begin());
    ll ans = lim<ll>::max();
    for(int x = 1; x <= m; x++) {
        ans = min(ans, base_cost - saved[x] - saved[x + m]);
    }
    cout << ans << endl;
}
int main() {
    long long n;
    scanf("%lld",&n);
    long long m;
    scanf("%lld",&m);
    std::vector<long long> a(n);
    for(int i = 0 ; i < n ; i++){
        scanf("%lld",&a[i]);
    }
    solve(n, m, std::move(a));
    return 0;
}
