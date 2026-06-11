#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#include "library/debug.cpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;
    vector<int> x(s.size() + 1), y(t.size() + 1);
    rep(i, 0, s.size()) {
        x[i + 1] = x[i] + (s[i] - 'A' + 1);
        x[i + 1] %= 3;
    }
    rep(i, 0, t.size()) {
        y[i + 1] = y[i] + (t[i] - 'A' + 1);
        y[i + 1] %= 3;
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int i = (x[b] - x[a - 1] + 3) % 3;
        int j = (y[d] - y[c - 1] + 3) % 3;
        if (i == j)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}