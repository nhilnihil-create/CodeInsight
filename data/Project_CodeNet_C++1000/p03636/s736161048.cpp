#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(s) (int)s.size()

int main() {
    string s;
    cin >> s;
    cout << s[0] << s.length() - 2 << s.back();
}