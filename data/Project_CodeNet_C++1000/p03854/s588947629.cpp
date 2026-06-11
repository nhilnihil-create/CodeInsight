#include <bits/stdc++.h>

using namespace std;

string s;

std::string replaceStringAll(std::string str,
                             const std::string &replace,
                             const std::string &with) {
    if (!replace.empty()) {
        std::size_t pos = 0;
        while ((pos = str.find(replace, pos)) != std::string::npos) {
            str.replace(pos, replace.length(), with);
            pos += with.length();
        }
    }
    return str;
}


void solve() {
    reverse(s.begin(), s.end());
    string divide[4] = {"dream", "dreamer", "erase", "eraser"};
    for (auto &i : divide) {
        reverse(i.begin(), i.end());
    }
    bool can = true;
    for (int j = 0; j < s.size();) {
        bool can2 = false;
        for (int k = 0; k < 4; ++k) {
            string d = divide[k];
            if (s.substr(j, d.size()) == d) {
                can2 = true;
                j += d.size();
            }
        }
        if (!can2) {
            can = false;
            break;
        }
    }
    if (can) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    cin >> s;
    solve();
    return 0;
}