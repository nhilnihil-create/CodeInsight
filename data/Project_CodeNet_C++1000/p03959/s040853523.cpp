#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> t(n), a(n);
    for (int i = 0; i < n; i++) {
        cin >> t.at(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    if (n == 1) {
        if (t.at(0) != a.at(0)) {
            cout << 0 << endl;
            return 0;
        }
    }

    vector<int> h(n);
    h.at(0) = t.at(0);
    h.at(n - 1) = a.at(n - 1);
    for (int i = 1; i < n; i++) {
        if (t.at(i - 1) < t.at(i)) {
            if (h.at(i) != 0 && h.at(i) != t.at(i)) {
                cout << 0 << endl;
                return 0;
            }
            h.at(i) = t.at(i); 
        }
    }
    for (int i = 1; i < n; i++) {
        if (a.at(i - 1) > a.at(i)) {
            if (h.at(i - 1) != 0 && h.at(i - 1) != a.at(i - 1)) {
                cout << 0 << endl;
                return 0;
            }
            h.at(i - 1) = a.at(i - 1);
        }
        if (h.at(i - 1) != 0 && h.at(i - 1) > a.at(i - 1)) {
            cout << 0 << endl;
            return 0;
        } 
    }
    
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        if (h.at(i) == 0) {
            ans *= (long long)min(t.at(i), a.at(i));
            ans %= MOD;
        }
    }

    cout << ans << endl;
}