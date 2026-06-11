#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    vector<long long> l(n, 0), h(n), t(n), a(n);
    cin >> t[0];
    l[0] = h[0] = t[0];
    for (int i = 1; i < n; i++) {
        cin >> t[i];
        if (t[i] > t[i-1]) {
            l[i] = h[i] = t[i];
        }
        else {
            h[i] = t[i];
            l[i] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    t.push_back(0);
    for (int i = n-1; i >= 0; i--) {
        if (t[i] > t[i+1]) {
            if (l[i] <= t[i] && t[i] <= h[i]) {
                l[i] = h[i] = t[i];
            }
            else {
                puts("0");
                return 0;
            }
        }
        else {
            h[i] = min(h[i], t[i]);
            if (l[i] > h[i]) {
                puts("0");
                return 0;
            }
        }
    }
    long long ans = 1, p = 1000000007;
    for (int i = 0; i < n; i++) {
        ans *= (h[i]-l[i]) + 1;
        ans %= p;
    }
    cout << ans << endl;
}