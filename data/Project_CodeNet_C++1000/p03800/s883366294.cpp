#include <bits/stdc++.h>
using namespace std;

int n;
char s[100004], ans[100004];

char rev(char c) { return c == 'S' ? 'W' : 'S'; }

int main() {
    cin >> n >> s;

    for (int i=0; i<n; i++) s[i] = (s[i] == 'o');

    for (int t=0; t<8; t++) {
        for (int i=0; i<3; i++) ans[i] = ((t >> i) & 1) ? 'S' : 'W';

        for (int i=1; i+2<n; i++) {
            if (s[i] == s[i+1]) ans[i+2] = ans[i-1];
            else ans[i+2] = rev(ans[i-1]);
        }

        bool okay = true;
        for (int i=0; i<n; i++) okay &= s[i] == ((ans[(i+n-1)%n] == 'S') + (ans[i] == 'S') + (ans[(i+1)%n] == 'S')) % 2;

        if (okay) {
            cout << ans << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
}