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
const int N = 2000;

signed main() {
    accell();
    int n;
    cin >> n;
    vector<int>p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }
    int cur = 1e9;
    int d = 1;
    vector<int>s(n);
    for (int i = 0; i < n; ++i) {
        s[p[i]] = cur;
        cur += d;
    }
    cur = 3e4;
    d = 3e4;
    vector<int>a(n), b(n);
    for (int i = 0; i < n; ++i) {
        a[i] = cur;
        b[i] = s[i] - cur;
        cur += d;
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; ++i) {
        cout << b[i] << ' ';
    }
    return 0;
}
