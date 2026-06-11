#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
int main() {
    int n;
    cin >> n;
    vector<int> t(n), a(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(a[0] != t.back()) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> h(n, -1), lb(n, 1);
    h[0] = t[0];
    for(int i = 1; i < n; i++) {
        if(t[i] != t[i - 1]) {
            h[i] = t[i];
        } else {
            lb[i] = t[i];
        }
    }
    if(h.back() != -1 && h.back() != a.back()) {
        cout << 0 << endl;
        return 0;
    }
    for(int i = n - 2; i >= 0; i--) {
        if(a[i] != a[i + 1]) {
            if(h[i] != -1 && h[i] != a[i]) {
                cout << 0 << endl;
                return 0;
            }
            if(h[i] == a[i]) {
                continue;
            }
            if(a[i] > lb[i]) {
                cout << 0 << endl;
                return 0;
            }
            lb[i] = 1;
        } else {
            lb[i] = min(lb[i], a[i]);
        }
    }
    ll ans = 1;
    lb.back() = 1;
    for(int i = 0; i < n; i++) {
        // cout << lb[i] << endl;
        ans *= lb[i];
        ans %= MOD;
    }
    cout << ans << endl;
}
