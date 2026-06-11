#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s[3];

    cin >> s[0] >> s[1] >> s[2];

    if((s[0][s[0].size()-1] == s[1][0])
        && (s[1][s[1].size()-1] == s[2][0])) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
