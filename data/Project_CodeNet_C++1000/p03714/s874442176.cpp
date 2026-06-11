#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector <int> a(3 * n);
    for (int i = 0; i < n * 3; ++ i) {
        cin >> a[i];
    }
    multiset <int> st;
    vector <ll> mx(3 * n), mn(3 * n);
    ll now;
    st.clear(); now = 0;
    for (int i = 0; i < n * 3; ++ i) {
        now += a[i];
        st.insert(a[i]);
        if (st.size() > n) {
            now -= *st.begin();
            st.erase(st.begin());
        }
        mx[i] = now;
    }
    st.clear(); now = 0;
    for (int i = n * 3 - 1; ~i; -- i) {
        now -= a[i];
        st.insert(-a[i]);
        if (st.size() > n) {
            now -= *st.begin();
            st.erase(st.begin());
        }
        mn[i] = now;
    }
    ll ans = -1e18;
    for (int i = n - 1; i < n * 2; ++ i) {
        ans = max(ans, mx[i] + mn[i + 1]);
    }
    cout << ans << endl;
    return 0;
}
