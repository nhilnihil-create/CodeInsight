#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    vector <int> L(n), R(n);
    vector <pair <int, int>> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && st.back().first >= p[i]) st.pop_back();
        if (st.empty()) L[i] = -1;
        else L[i] = st.back().second;
        st.push_back({p[i], i});
    }
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && st.back().first >= p[i]) st.pop_back();
        if (st.empty()) R[i] = n;
        else R[i] = st.back().second;
        st.push_back({p[i], i});
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) ans += (ll)p[i] * (i - L[i]) * (R[i] - i);
    cout << ans << '\n';
}