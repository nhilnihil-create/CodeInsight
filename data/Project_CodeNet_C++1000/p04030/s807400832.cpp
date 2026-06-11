#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    string s;
    cin >> s;
    string ans = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'B') {
            if (!ans.empty()) ans.pop_back();
        } else {
            ans += s[i];
        }
    }

    cout << ans << endl;

    return 0;
}