#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;
// ------------------------------

int main() {
    string S;
    cin >> S;
    bool s = false, e = false, n = false, w = false;
    rep(i, S.size()) {
        if (S[i] == 'S') s = true;
        if (S[i] == 'E') e = true;
        if (S[i] == 'N') n = true;
        if (S[i] == 'W') w = true;
    }
    if ((s && !n) || (!s && n) || (e && !w) || (!e && w)) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}