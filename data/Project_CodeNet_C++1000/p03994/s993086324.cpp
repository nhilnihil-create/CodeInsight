#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;

    int n = s.length();

    string ans;
    for (int i = 0; i < n - 1; i++) {
        int toa = ('z' - s[i] + 1) % 26;
        if (toa <= k) {
            k -= toa;
            ans += 'a';
        } else {
            ans += s[i];
        }
    }

    int d = (s[n - 1] - 'a' + k) % 26;
    ans += (char) ('a' + d);

    cout << ans << endl;
    return 0;
}