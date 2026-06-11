#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    if (n == 1) {
        cout << 3 << endl;
        return 0;
    }

    long long ans;
    int left;
    if (s1.at(0) == s1.at(1)) {
        ans = 6;
        left = 2;
    }
    else {
        ans = 3;
        left = 1;
    }

    for (int i = left; i < n; i++) {
        if (i + 1 < n) {
            if (s1.at(i) == s1.at(i + 1)) {
                if (s1.at(i - 1) == s2.at(i - 1)) {
                    ans *= 2;
                    ans %= MOD;
                }
                else {
                    ans *= 3;
                    ans %= MOD;
                }
            }
            else {
                if (s1.at(i - 1) == s2.at(i - 1)) {
                    ans *= 2;
                    ans %= MOD;
                }
            }
        }
        else {
            if (s1.at(i - 1) == s2.at(i - 1)) {
                    ans *= 2;
                    ans %= MOD;
                }
        }
    }

    cout << ans << endl;
}