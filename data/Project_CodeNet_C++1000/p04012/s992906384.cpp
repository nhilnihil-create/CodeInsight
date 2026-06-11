#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    map <char,int> mp;
    for (int i = 0; i < (int)s.length(); i++) {
        mp[s[i]]++;
    }
    string ans = "Yes";
    for (int i = 0; i < (int)s.length(); i++) {
        if (mp[s[i]]%2) {
            ans = "No";
            break;
        }
    }
    cout << ans << endl;
}