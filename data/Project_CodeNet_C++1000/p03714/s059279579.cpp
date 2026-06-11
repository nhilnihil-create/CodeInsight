#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
ll in[3 * N], foo[3 * N], bar[3 * N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 3 * n; ++i) scanf("%lld", in + i);

    multiset< ll> st;

    ll s = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        st.insert(in[i]);
        s += in[i];
        if (i > n) {
            ll x = *st.begin();
            s -= x;
            st.erase(st.begin());
        }

        foo[i] = s;
    }

    st.clear();
    s = 0;
    for (int i = 3 * n; i >= 1; i--) {
        st.insert(in[i]);
        s += in[i];
        if (i <= 2 * n) {
            ll x = *(--st.end());
            st.erase(--st.end());
            s -= x;
        }
        bar[i] = s;
    }

    ll res = -1e18;
    for (int i = n; i <= 2 * n; i++) {
        res = max(res, foo[i] - bar[i + 1]);
    }
    cout << res << endl;
}