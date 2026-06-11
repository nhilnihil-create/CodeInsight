#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    string ans = "";
    for (int i = 0; i < 1; ++i) {
        ans += toupper(s1[0]);
    }
    for (int i = 0; i < 1; ++i) {
        ans += toupper(s2[0]);
    }
    for (int i = 0; i < 1; ++i) {
        ans += toupper(s3[0]);
    }
    cout << ans << "\n";
}










