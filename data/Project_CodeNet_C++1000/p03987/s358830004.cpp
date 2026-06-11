 #pragma GCC optimize("O3")
 #pragma GCC optimize("unroll-loops")
 #pragma GCC optimize("fast-math")
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define int long long
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

void accell() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
}
const int N = 1e5 + 5;

int dp[N][4];

signed main() {
    accell();
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    stack<pair<int, int> > st;
    int cur = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (st.empty()) {
            st.push({a[i], i});
            cur += a[i];
            ans += cur;
            continue;
        }
        int lst = i;
        while (st.size() > 0 && a[i] <= st.top().F) {
            cur -= st.top().F * (lst - st.top().S);
            lst = st.top().S;
            st.pop();
        }
        st.push({a[i], lst});
        cur += (i - lst + 1) * a[i];
        ans += cur;
    }
    cout << ans << '\n';
    return 0;
}
