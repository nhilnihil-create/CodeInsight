#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP (i, 0, n)

#define eb emplace_back

using namespace std;

typedef long long ll;

const int INF = 1 << 29;

int main() {
    string s;
    cin >> s;
    vector<char> vc;

    rep (i, s.size()) {
        if (s[i] == 'B') {
            if (vc.size() != 0) {
                vc.pop_back();
            }
        } else {
            vc.push_back(s[i]);
        }
    }

    rep (i, vc.size()) {
        cout << vc[i];
    }
    cout << endl;
}
