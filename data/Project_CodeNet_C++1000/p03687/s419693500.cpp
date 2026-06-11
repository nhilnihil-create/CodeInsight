#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
//printf("%.10f\n", n);
ll ok[12345678];
signed main() {
    ll n, a, cnt = 0, ans = INF;
    string s; cin >> s;
    for (int h = 97; h < 123; h++) {
        ll z = 0; string t = s; cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if ((ll)s[i] == h) { z++; }
        }
        if (z == 0) { continue; }
        while (true) {
            z = 0;
            for (int i = 0; i < t.size(); i++) {
                if ((ll)t[i] != h) { z++; }
            }
            if (z == 0) { ans = min(ans, cnt); break; }
            for (int i = 1; i < t.size(); i++) {
                if ((ll)t[i] == h) { t[i - 1] = t[i]; }
            }
            t.pop_back(); cnt++;
        }
    }
    cout << ans << endl;
    return 0;
}