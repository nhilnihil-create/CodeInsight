#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
    string s; cin >> s;
    bool flag = 1;
    rep(i, s.size()) {
        if (s.at(i) != s.at(s.size()-1-i)) flag = 0;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}