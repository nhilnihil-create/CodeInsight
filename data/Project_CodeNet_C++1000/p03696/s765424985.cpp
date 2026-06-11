#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    string mod_s = s;
    stack<int> brackets;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            brackets.push(0);
        } else {
            if (brackets.empty())
                mod_s = '(' + mod_s;
            else
                brackets.pop();
        }
    }
    while (!brackets.empty()) {
        brackets.pop();
        mod_s += ')';
    }
    cout << mod_s;
}