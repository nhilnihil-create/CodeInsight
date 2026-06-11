#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s;
    cin >> s;

    string ans;
    for (int i=0; i<s.size(); i++) {
        if (i % 2 == 0) ans += s[i];
    }

    cout << ans << endl;

    return 0;
}