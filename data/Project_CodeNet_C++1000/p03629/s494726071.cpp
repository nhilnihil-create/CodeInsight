#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, d[200005][26] = {}, b[200005] = {};
    string s, z;
    cin >> s;
    n = (int)s.length();
    for (int i = 0; i < 26; i++) d[n][i] = n + 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) d[i][j] = d[i + 1][j];
        d[i][s[i] - 'a'] = i + 1;
        //for (int j = 0; j < 26; j++) cout << d[i][j] << ' '; cout << '\n';
    }
    for (int i = n; i >= 0; i--) {
        b[i] = 890328;
        for (int j = 0; j < 26; j++) b[i] = min(b[i], b[d[i][j]] + 1);
        //cout << i << ' ' << b[i] << '\n';
    }
    int c = 0;
    for (int i = b[0]; i; i--) {
        int e = 0;
        for (int j = 0; j < 26; j++) if (b[d[c][j]] == i - 1) {e = j; c = d[c][j]; break;}
        z += (char)(e + 'a');
    }
    cout << z;
}
