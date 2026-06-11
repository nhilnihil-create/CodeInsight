#include<bits/stdc++.h>
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define print(x) cout << (x) << endl;
#define printa(x, n) for(ll i = 0; i < n; i++) {cout << (x[i]) << " ";} cout << endl;
using namespace std;
using ll = long long;

int main(void) {
    string s;
    int k;
    cin >> s >> k;

    rep (i, s.size()) {
        if (i == s.size() - 1) {
            s[i] = char(((s[i] - 'a') + k) % 26 + 97);
            break;
        }
        if (s[i] == 'a') continue;
        if ((26 - (int)(s[i] - 'a')) - k <= 0) {
            k -= 26 - (int)(s[i] - 'a');
            s[i] = 'a';
        }
    }
    
    cout << s << endl;
    return 0;
}
