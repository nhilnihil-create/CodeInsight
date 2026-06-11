#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < int(n); i++)
#define FOR(i,n,m) for(int i = int(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9 + 6;
const ll LLINF = 1e18 + 1;

int main() {
    int n; cin >> n;
    vector<int> a(n), b(n+1);
    REP(i, n) {
        scanf("%d", &a[i]);
        b[a[i]] = i;
    }
    set<int> st;
    st.insert(-1);
    st.insert(n);
    ll ans = 0;
    FOR(i,1,n+1) {
        auto lw = st.lower_bound(b[i]);
        ans += (ll)(*(lw)-b[i]) * (b[i] - *(--lw)) * i;
        st.insert(b[i]);
    }
    cout << ans << endl;
    return 0;
}