#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    t /= 2;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mx = 0;
    int ans = 0;
    for (int i = n  - 1; i >= 0; i--) {
        if (mx > a[i]) {
            ans = max(ans, mx - a[i]);
        }
        mx = max(mx, a[i]);
    }
    int res = 0;
    map <int, int> c;
    for (int i = n - 1; i >= 0; i--) {
        c[a[i]]++;
        if (c[a[i] + ans]) {
            res++;
        }
    }
    cout << res << '\n';
    return 0;
}