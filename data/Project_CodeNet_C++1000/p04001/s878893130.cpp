#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    for (int m = 0; m < (1 << (n - 1)); m++) {
        string t;
        vector <string> r;
        for (int i = 0; i < n; i++) {
            t += s[i];
            if ((m >> i) & 1) {
                r.push_back(t);
                t.clear();
            }
        }
        r.push_back(t);
        for (auto to : r) {
            ll x = stoll(to);
            ans += x;
        }
    }  
    cout << ans << '\n';
    return 0;
} 