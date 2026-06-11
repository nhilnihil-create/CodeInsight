#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(std::string s) {
    string ans = "";
    rep(i, s.length()) {
        if (s[i] == '0') {
            ans.push_back('0');
        } else if (s[i] == '1') {
            ans.push_back('1');
        } else {
            if (ans.length() != 0) {
                ans.pop_back();
            }
        }
    }
    cout << ans << endl;
}

int main() {
    std::string s;
    std::cin >> s;
    solve(s);
    return 0;
}
