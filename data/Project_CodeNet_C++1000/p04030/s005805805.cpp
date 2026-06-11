#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    vector<char> S;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B' && S.size() > 0) {
            S.pop_back();
        } else if (s[i] != 'B') {
            S.push_back(s[i]);
        }
    }

    for (int i = 0; i < S.size(); i++) {
        cout << S[i];
    }
    cout << endl;

    return 0;
}
