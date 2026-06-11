#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s;
    cin >> s;

    vector<char> ans;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '0') ans.emplace_back('0');
        else if (s[i] == '1') ans.emplace_back('1');
        else if (!ans.empty()) ans.pop_back();
    }

    for (auto x : ans) cout << x;
    cout << endl;

    return 0;
}