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
    ll N;
    cin >> N;
    vector<ll> A(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> A[i];
    }
    vector<ll> ac(N);
    copy(A.begin(), A.end(), ac.begin());
    ac.push_back(0);
    sort(ac.begin(), ac.end());
    ac.erase(unique(ac.begin(), ac.end()), ac.end());
    vector<ll> a(N);
    for ( int i = 0; i < N; i++ ) {
        a[i] = lower_bound(ac.begin(), ac.end(), A[i]) - ac.begin();
    }

    BIT<ll> b(N+1, 0);
    vector<int> mi;
    ll am = 0;
    for ( int i = 0; i < N; i++ ) {
        b.add(1,1);
        b.add(a[i] + 1, -1);
        if ( am < a[i] ) {
            am = a[i];
            mi.push_back(i);
        }
    }

    vector<ll> ans(N);
    int ib = 1;
    for( int i : mi ) {
        while ( ib <= a[i] ) {
            ll na = ac[ib] - ac[ib-1];
            ll nb = b.sum(ib);
            ans[i] += na * nb;
            ib++;
        }
    }

    for ( int i = 0; i < N; i++ ) {
        cout << ans[i] << "\n";
    }
    return 0;
}

int main() {
    solve();
    return 0;
}
