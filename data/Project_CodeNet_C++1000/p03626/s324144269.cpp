#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;

    ll ans = 1;

    int pattern;
    int start;
    if (s1[0] == s2[0]) {
        ans *= 3;
        start = 1;
        pattern = 1;
    } else {
        ans *= 6;
        start = 2;
        pattern = 2;
    }

    for (int i = start; i < n; ++i) {
        if (s1[i] == s2[i]) {
            if (pattern == 1) {
                ans *= 2;
            } else {
                ans *= 1;
            }

            ans %= (ll)MOD;
            pattern = 1;
        } else {
            if (pattern == 1) {
                ans *= 2;
            } else {
                ans *= 3;
            }

            ans %= (ll)MOD;
            i++;
            pattern = 2;
        }
    }

    cout << ans << endl;
}