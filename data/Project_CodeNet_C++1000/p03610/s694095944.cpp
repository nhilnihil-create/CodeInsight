#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(s) (int)s.size()

int main() {
    string s, res = "";
    cin >> s;
    for (int i = 0; i < (int)s.length(); i += 2) res.push_back(s[i]);
    cout << res;
}