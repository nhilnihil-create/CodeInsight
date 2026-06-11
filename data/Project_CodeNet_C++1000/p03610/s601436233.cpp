#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    string s;
    cin >> s;

    rep(i, s.size()) if (i % 2 == 0) cout << s[i];
    cout << endl;

    return 0;
}