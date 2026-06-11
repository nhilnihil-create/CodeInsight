#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    string t = "";
    for (int i = s.size() - 1; i >= 0; i--) {
        t += s[i];
        if (t == "maerd" || t == "remaerd" || t == "esare" || t == "resare") {
            t = "";
        }
    }
    if (t == "") cout << "YES" << '\n';
    else cout << "NO" << '\n';
    return 0;
}