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
    ll N, M;
    cin >> N >> M;
    vector<ll> L(N), R(N);
    vector<pair<ll, int>> D;
    for ( int i = 0; i < N; i++ ) {
        cin >> L[i] >> R[i];
        D.emplace_back(R[i]-L[i]+1, i);
    }
    sort(D.begin(), D.end());
    vector<ll> ans(M+1);
    BIT<ll> sl(M+2), sh(M+2);

    int p = N-1;
    for ( int d = M; d >= 1; d-- ) {
        while ( p >= 0 && D[p].first >= d ) {
            sl.add(1, 1);
            sl.add(D[p].first + 1, -1);
            p--;
        }
        ans[d] += sl.sum(d);

        // for ( int m = 0; m <= M; m++ ) {
        //     cout << sl.sum(m) << " ";
        // }
        // cout << "\n";
    }

    p = 0;
    for ( int d = 1; d <= M; d++ ) {
        while ( p < N && D[p].first < d ) {
            int i = D[p].second;
            sh.add(L[i], 1);
            sh.add(R[i]+1, -1);
            p++;
        }
        for ( int j = 0; j <= M; j+=d ) {
            ans[d] += sh.sum(j);
        }

        // for ( int m = 0; m <= M; m++ ) {
        //     cout << sh.sum(m) << " ";
        // }
        // cout << "\n";
    }

    for ( int i = 1; i <= M; i++ ) {
        cout << ans[i] << "\n";
    }
    return 0;
}

int main() {
    solve();
    return 0;
}