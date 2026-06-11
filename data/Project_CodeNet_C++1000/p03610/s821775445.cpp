#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, res = "";
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (i % 2 == 0) res += s[i];
    }

    cout << res << endl;
}