#include <bits/stdc++.h>
using namespace std;

int main() {
    string a = "CODEFESTIVAL2016";
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a.at(i) != s.at(i)) {
            ans += 1;
        }
    }
    cout << ans << endl;
}