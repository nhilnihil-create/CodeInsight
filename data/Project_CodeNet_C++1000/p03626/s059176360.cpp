#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;
string s1, s2;
const lint mod = 1e9 + 7;

int main() {
    cin >> n >> s1 >> s2;
    int now = 0;
    lint ans = 1;
    while (now < n) {
        bool now_vertical = s1[now] == s2[now];
        if (now == 0) {
            if (now_vertical) {
                ans = ans * 3 % mod;
            } else {
                ans = ans * 6 % mod;
            }
        } else {
            bool before_vertical = s1[now - 1] == s2[now - 1];
            lint mult;
            if (before_vertical) {
                mult = 2;
            } else {
                if (now_vertical) {
                    mult = 1;
                } else {
                    mult = 3;
                }
            }
            ans = ans * mult % mod;
        }
        if (now_vertical) {
            now += 1;
        } else {
            now += 2;
        }
    }
    cout << ans << endl;
}