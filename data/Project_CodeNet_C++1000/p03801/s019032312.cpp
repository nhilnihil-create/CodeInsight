#include <bits/stdc++.h>
/*
    p = 
*/
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], best[maxn];
int n;
long long cnt[maxn];
int main() {
#ifdef LDT
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    best[1] = 1;
    for (int i = 1; i <= n; ++i) {
        best[i] = best[i - 1];
        if (a[i] > a[best[i]]) best[i] = i;
    }
    int cur = best[n];
    map<int, int> st;
    for (int j = cur + 1; j <= n; ++j)
        st[a[j]] += 1;
    while (cur != 1) {
        int nxt = best[cur - 1];
        pair<int, int> ele = {a[nxt], 1};
        cnt[cur] += a[cur] - a[nxt];
        while (st.size() && st.rbegin()->first >= a[nxt]) {
            int diff = st.rbegin()->first - a[nxt];
            cnt[cur] += 1ll * diff * st.rbegin()->second;
            
            ele.second += st.rbegin()->second;
            auto it = st.end();
            --it;
            st.erase(it);
        }
        for (int j = nxt + 1; j < cur; ++j)
            st[a[j]] += 1;
        st[ele.first] += ele.second;
        cur = nxt ;
    }
    st[a[1]] += 1;
    for (auto it : st)
        cnt[1] += 1ll * it.first * it.second;
    for (int i = 1; i <= n; ++i)
        cout << cnt[i] << '\n';
    return 0;
}