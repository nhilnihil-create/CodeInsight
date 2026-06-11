#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T> struct BIT {
    int max_n;
    vector<T> data;
    const T unit;
    BIT<T>(int n, T u = T(0)) : max_n(n), unit(u) {
        data.assign(max_n + 1, u);
    }
    void add(int i, T x) {
        while ( i <= max_n ) {
            data[i] += x;
            i += i & -i;
        }
    }
    T sum(int i) {
        T s = unit;
        while ( i > 0 ) {
            s += data[i];
            i -= i & -i;
        }
        return s;
    }
};

ll solve() {
    ll N, K, a;
    cin >> N >> K;
    vector<ll> cum(N+1);
    for ( int i = 0; i < N; i++ ) {
        cin >> a;
        cum[i+1] = cum[i] + a - K;
    }

    vector<ll> cp(N+1);
    for ( int i = 0; i <= N; i++ ) cp[i] = cum[i];
    sort(cp.begin(), cp.end());
    cp.erase(unique(cp.begin(), cp.end()), cp.end());
    for ( int i = 0; i <= N; i++ ) {
        cum[i] = lower_bound(cp.begin(), cp.end(), cum[i]) - cp.begin() + 1;
    }

    ll ans = 0;
    BIT<ll> b(N+1);
    for ( int i = 0; i <= N; i++ ) {
        ans += b.sum(cum[i]);
        b.add(cum[i], 1);
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}