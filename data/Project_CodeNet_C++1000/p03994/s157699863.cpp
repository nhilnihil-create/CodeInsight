#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, a, b) for (int i=a; i<(b); ++i)
#define reprev(i, n) for (int i=n-1; i>=0; --i)
#define reprrev(i, a, b) for (int i=b-1; i>=(a); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cout << fixed << setprecision(10);
    
    string s; cin >> s;
    int k; cin >> k;
    int zint = 'z' - 'a';
    rep(i, s.size()) {
        int sint = s[i] - 'a';
        if (sint == 0) continue;
        int fora = zint - sint + 1;
        if (fora <= k) {
            s[i] = 'a';
            k -= fora;
        }
    }
    int mk = s[s.size()-1] - 'a' + k;
    mk %= 26;
    s[s.size() - 1] = char('a' + mk);
    cout << s << endl;
    return 0;
}