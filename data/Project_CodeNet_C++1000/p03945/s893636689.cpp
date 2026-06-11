#include <bits/stdc++.h>
using namespace std;
void solve () {
    string s;
    cin >> s;
    char r = s[0];
    int ans = 0;
    int n = (int) s.size();
    for (int i = 1; i < n; i++) {
        if (r != s[i]) {
            ans++;
            r = s[i];
        }
    }
    cout << ans;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
