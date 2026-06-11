#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    string ans;
    rep(i,s.size()) {
        if (s.at(i) == 'B') {
            if (!ans.empty()) {
                ans.erase(ans.size() - 1);
            }
        } else {
            ans.push_back(s.at(i));
        }
    }
    cout << ans << endl;
}
