/**
 *    author:  FromDihPout
 *    created: 2020-08-03
**/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    
    long long ans;
    int i;
    bool prev; // true if vertical, false if horizontal
    if (s1[0] == s2[0]) {
        ans = 3;
        i = 1;
        prev = true;
    }
    else {
        ans = 6;
        i = 2;
        prev = false;
    }
    while (i < n) {
        if (s1[i] == s2[i] && prev) {
            ans *= 2;
            i++;
            prev = true;
        }
        else if (s1[i] == s2[i]) {
            i++;
            prev = true;
        }
        else if (prev) {
            ans *= 2;
            i += 2;
            prev = false;
        }
        else {
            ans *= 3;
            i += 2;
            prev = false;
        }
        ans %= MOD;
    }
    cout << ans << '\n';
    return 0;
}