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
int n;
bool check(int x, vector<int>&a) {
    vector<int>b(a.size());
    for (int i = 0; i < a.size(); ++i)
        b[i] = a[i] >= x;
    for (int i = 0; i + 1 < n; ++i) {
        if ((b[n + i - 1] ^ b[n + i]) == 0)
            return b[n + i];
        if ((b[n - i - 1] ^ b[n - i - 2]) == 0)
            return b[n - i - 1];
    }
    return b[0];
}


signed main() {
    accell();
    cin >> n;
    vector<int>a(2 * n - 1);
    for (int i = 0; i < 2 * n - 1; ++i)
        cin >> a[i];
    int l = 0;
    int r = 2 * n;
    while (r - l > 1) {
        int m = l + r >> 1;
        // cout << l << ' ' << r << endl;
        if (!check(m, a))
            r = m;
        else
            l = m;
    }
    cout << l << endl;
    return 0;
}
