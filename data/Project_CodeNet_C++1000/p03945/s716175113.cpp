#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    int ans = 0;
    rep(i, s.size() - 1) {
        if(s[i] != s[i + 1]) ans++;
    }
    cout << ans << endl;
    return 0;
}
