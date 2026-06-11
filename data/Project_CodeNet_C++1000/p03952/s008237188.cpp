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



signed main() {
    accell();
    int n, x;
    cin >> n >> x;
    if (x == 1 || x == 2 * n - 1) {
        cout << "No";
        return 0;
    }
    if (n == 2) {
        cout << "Yes\n1\n2\n3\n";
        return 0;
    }
    set<int>st;
    vector<int>a(2 * n - 1);
    vector<bool>used(2 * n - 1);
    n = n * 2 - 1;
    if (x >= 3) {
        a[n / 2] = x + 1;
        a[n / 2 + 1] = x;
        a[n / 2 + 2] = x - 1;
        a[n / 2 - 1] = x - 2;
    } else {
        a[n / 2 - 1] = x + 2;
        a[n / 2] = x - 1;
        a[n / 2 + 1] = x;
        a[n / 2 + 2] = x + 1;
    }
    for (int i = 1; i <= n; ++i)
        st.insert(i);
    for (int i = n / 2 - 1; i <= n / 2 + 2; ++i) {
        st.erase(a[i]), used[i] = true;
    }
    n = (n + 1) / 2;
    for (int i = 0; i < 2 * n - 1; ++i) {
       // cout << *st.begin() << ' ';
        if (!used[i]) {
            a[i] = *st.begin();
            st.erase(a[i]);
        }
    }
    cout << "Yes\n";
    for (auto &i : a)
        cout << i << '\n';
    return 0;
}
