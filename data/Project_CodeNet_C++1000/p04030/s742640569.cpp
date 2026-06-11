#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    string s; cin >> s;
    vector<char> ans;
    rep(i, s.size()) {
        char x = s.at(i);
        if (x == '0' || x == '1') {
            ans.push_back(x);
        } else if (x == 'B' && ans.size() > 0) {
            ans.pop_back();
        }
    }
    rep(i, ans.size()) cout << ans.at(i);
    cout << endl;
}