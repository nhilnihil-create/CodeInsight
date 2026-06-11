#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
//printf("%.10f\n", n);
ll yo[12345678], ta[12345678];
signed main() {
    ll n = 0, m;
    string s; cin >> s >> n;
    for (int h = 0; h < s.size(); h++) {
        if (s[h] != 'a' && (ll)s[h] + n >= 123) {
            n -= (123 - (ll)s[h]); s[h] = 'a';
        }
    }
    while ((ll)s[s.size() - 1] + n >= 123) {
        n -= 26;
    }
    s[s.size() - 1] = (char)((ll)s[s.size() - 1] + n);
    cout << s << endl;
    return 0;
}