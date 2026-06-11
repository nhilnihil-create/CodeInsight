#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(s) (int)s.size()

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    bool ok = (a.back() == b[0] && b.back() == c[0]);
    cout << (ok ? "YES" : "NO");
}