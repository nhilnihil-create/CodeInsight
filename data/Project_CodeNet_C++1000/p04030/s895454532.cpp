#include <bits/stdc++.h>
using namespace std;
int main() {
ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    string ans = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'B') {
            if (ans.length() > 0) {
                ans.erase(ans.length() - 1 , 1);
            }
        }
        else {
            ans += s[i];
        }
    }
    cout << ans << endl;
}