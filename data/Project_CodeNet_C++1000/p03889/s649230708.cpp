#include <bits/stdc++.h>

using namespace std;

string s1 = "bdpq", s2 = "dbqp";

bool judge(string s) {
    int n = s.length();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            if (s[i] != s1[j]) continue;
            if (s[n - i - 1] != s2[j]) return false;
            break;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    cout << (judge(s) ? "Yes" : "No") << endl;
    return 0;
}