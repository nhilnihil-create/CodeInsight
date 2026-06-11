#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    
    int cnt[26] = {};
    for (auto c: s) {
        cnt[c-'a']++;
    }
    
    ll n = s.length();
    ll ans = n * (n-1) / 2 + 1;
    
    for (auto e: cnt) {
        ans -= (ll)e * (e-1) / 2;
    }
    
    cout << ans << endl;
    
    return 0;
}
