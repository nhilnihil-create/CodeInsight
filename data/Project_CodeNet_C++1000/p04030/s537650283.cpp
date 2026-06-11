#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<char> act_s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != 'B') {
            act_s.push_back(s[i]);
        } else {
            if (!act_s.empty()) {
                act_s.pop_back();
            }
        }
    }
    string new_s = "";
    for (int i = 0; i < act_s.size(); i++) {
        new_s += act_s[i];
    }
    cout << new_s;
}