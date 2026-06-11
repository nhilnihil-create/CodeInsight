#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int d = 0, c = 0;
    rep(i, n) {
        if (s[i] == '(')
            c++;
        else
            c--;
        d = min(d, c);
    }

    rep(i, -d) cout << '(';
    cout << s;
    rep(i, c - d) cout << ')';

    return 0;
}
