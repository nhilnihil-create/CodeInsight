#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s; cin >> s;
    int l = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i-1] != s[i]) {
            l = i-1;break;
        }
        l++;
    }

    int r = s.size()-1;
    int ans = 0;
    char c = s[s.size()-1];

    for (int i = s.size()-1-1; i >= 0; i--) {
        if (i == l) {
            ans++;
            break;
        }
        if (s[i] == c) continue;
        c = s[i];
        ans++;
    }
    cout << ans << endl;
}
