#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    set<int> st;
    rep(i, n) {
        int a;
        cin >> a;
        st.insert(a);
    }

    int ans = st.size();
    if ((n - ans) % 2 == 1)
        ans--;

    cout << ans << endl;

    return 0;
}