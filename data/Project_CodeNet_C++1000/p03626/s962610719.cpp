#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;

void solve() {
    int n, cur = 3, pred=0;
    long long ans=1;
    string s1, s2;
    cin >> n;
    cin >> s1;
    cin >> s2;
    for (int i=0; i<n; ++i) {
        if (pred == 0)
            cur = 3;
        if (s1[i] == s2[i]) {
            if (pred == 1) {
                cur = 2;
            } else if (pred == 2) {
                cur = 1;
            }
            ans = (ans *= cur) % mod;
            pred = 1;
        } else {
            if (pred == 1) {
                cur = 2;
                ans = (ans *= cur * (cur - 1)) % mod;
            } else if (pred == 2) {
                ans = (ans *= 3LL) % mod;
            } else if (pred == 0) {
                cur = 3;
                ans = (ans *= cur * (cur - 1)) % mod;
            }
            ++i;
            pred = 2;
        }
    }
    cout << ans;
}

int main() {

	solve();
    return 0;
}
