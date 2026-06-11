#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int n, mx, ok = 1;
multiset <int> st;

void izbaci (int x) {
    if (st.find(x) == st.end()) {
        ok = 0;
        return;
    }
    st.erase(st.find(x));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        st.insert(x);
    }
    mx = *st.rbegin();
    for (int i = 0; i <= mx; i++) {
        izbaci(max(i, mx - i));
    }
    int lo = (mx + 1) / 2 + 1;
    for (auto x : st) {
        if (!(lo <= x && x <= mx)) ok = 0;
    }
    if (ok) cout << "Possible"; else cout << "Impossible";
    return 0;
}
