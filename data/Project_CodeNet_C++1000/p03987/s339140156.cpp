#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        p[--a[i]] = i;
    }

    set<int> st;
    st.insert(-1), st.insert(n);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        auto itr = st.lower_bound(p[i]);
        int r = *itr - p[i];
        itr--;
        int l = p[i] - *itr;
        ans += (ll)(i + 1) * r * l;
        st.insert(p[i]);
    }
    cout << ans << endl;
}