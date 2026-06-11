#include <bits/stdc++.h>
using namespace std;
using Pi = pair<int, int>;
using ll = long long;

int main() {
    int N;
    set<int> st;
    Pi data[200005];
    ll ans = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> data[i].first;
        data[i].second = i;
    }
    sort(data, data + N);
    st.insert(-1);
    st.insert(N);
    for (int i = 0; i < N; i++) {
        ll p = data[i].second;
        ll r = *st.lower_bound(p);
        ll l = *(--st.lower_bound(p));
        ans += (r - p) * (p - l) * data[i].first;
        st.insert(p);
    }

    cout << ans << endl;
    return (0);
}