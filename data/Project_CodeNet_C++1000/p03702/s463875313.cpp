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
template <typename T, typename Can> T bsearch(T L, T R, Can&& can, bool left_feasible = true) {
    static_assert(is_convertible<decltype(can), function<bool(T)>>::value, "can must be bool(T)");
    T& feasible = left_feasible ? L : R;
    T& infeasible = left_feasible ? R : L;
    while(R - L > 1) {
        T M = L + (R - L) / 2;
        (can(M) ? feasible : infeasible) = M;
    }
    return feasible;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> h(n);
    cin >> h;
    cout << bsearch<ll>(0, 1'000'000'000, [&](ll k) {
        ll tot = 0;
        for(int hi : h) {
            tot += (max(0ll, hi - k * b) + (a - b) - 1) / (a - b);
        }
        return tot <= k;
    }, false) << endl;
    return 0;
}
