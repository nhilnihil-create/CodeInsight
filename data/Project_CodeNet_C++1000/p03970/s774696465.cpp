#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s; cin >> s;
    string t;
    t = "CODEFESTIVAL2016";

    int ans = 0;
    rep(i, t.size()) {
        if (s.at(i) != t.at(i))
            ans++;
    }

    cout << ans << endl;
    return 0;
}