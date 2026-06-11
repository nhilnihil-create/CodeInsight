#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, ans = "";
    cin >> s;

    for (int i = 0; i < s.length(); ++i) {
        if (i % 2 == 0) {
            ans += s.at(i);
        }
    }

    cout << ans << endl;

    return 0;
}