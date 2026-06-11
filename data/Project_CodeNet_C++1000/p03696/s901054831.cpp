#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void solve() {
    int n;
    string str;
    cin >> n >> str;

    stack<int> l, r;
    int x = 0;
    rep(i, n) {
        if (str[i] == '(') {
            l.push(0);
        } else if (l.empty()) {
            r.push(0);
        } else {
            l.pop();
        }
    }

    // cout << l.size() << " " << r.size() << endl;

    rep(i, r.size()) cout << "(";
    cout << str;
    rep(i, l.size()) cout << ")";
    cout << endl;
}

int main() {
    solve();
    return 0;
}
