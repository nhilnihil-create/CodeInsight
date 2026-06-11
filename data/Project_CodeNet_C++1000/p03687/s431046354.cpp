#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    string s;
    ll ans = LONG_LONG_MAX;
    cin >> s;
    for(char i = 'a';i <= 'z';i++) {
        ll maxi = -1;
        ll prev = -1;
        for(ll j = 0;j < s.size();j++) {
            if(i == s[j]) {
                maxi = max(maxi, j - prev - 1);
                prev = j;
            }
        }
        if(maxi >= 0) {
            maxi = max((ll)s.size() - 1 - prev, maxi);
            ans = min(ans, maxi);
        }
    }
    cout << ans << endl;
    return 0;
}
