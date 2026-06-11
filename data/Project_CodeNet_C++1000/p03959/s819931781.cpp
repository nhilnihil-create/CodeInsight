#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    ll t[n], a[n];
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ht[n], ah[n];
    ll t_max = -1, a_max = -1;
    for (int i = 0; i < n; i++) {
        if (t_max < t[i]) {
            t_max = t[i];
            ht[i] = t[i];
        } else if (t[i] <= t_max) {
            ht[i] = -1;
        }
        if (a_max < a[n - i - 1]) {
            a_max = a[n - i - 1];
            ah[n - i - 1] = a[n - i - 1];
        } else if (a[n - i - 1] <= a_max) {
            ah[n - i - 1] = -1;
        }
    }
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        if (ht[i] != -1 && ah[i] == -1) {
            if (ht[i] > a[i]) ans = 0;
        } else if (ht[i] != -1 && ah[i] != -1) {
            if (t[i] < ah[i] || a[i] < ht[i]) ans = 0;
        } else if (ht[i] == -1 && ah[i] == -1) {
            ans *= min(t[i], a[i]);
            ans %= mod;
        } else if (ht[i] == -1 && ah[i] != -1) {
            if (t[i] < ah[i]) ans = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
