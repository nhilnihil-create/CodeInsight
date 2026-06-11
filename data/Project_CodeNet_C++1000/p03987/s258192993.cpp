#include <bits/stdc++.h>

using namespace std;

long long b[200000 + 5];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        b[a] = i;
    }

    set<long long> st;
    st.insert(0);
    st.insert(n + 1);

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        st.insert(b[i]);
        auto it = st.find(b[i]);
        long long lo = *(--it);
        it++;
        long long hi = *(++it);
        ans += i * (b[i] - lo) * (hi - b[i]);
    }

    cout << ans << endl;
    return 0;
}