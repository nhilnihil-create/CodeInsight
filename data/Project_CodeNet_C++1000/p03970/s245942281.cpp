#include <bits/stdc++.h>

using namespace std;


int main() {
    string s;
    cin >> s;
    string t = "CODEFESTIVAL2016";
    int ans = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != t[i]) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}