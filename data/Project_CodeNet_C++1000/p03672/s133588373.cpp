#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size();
    for (int i = 1; i < n; i++) {
        string c = s.substr(n - i);
        if ((n - i) & 1) continue;
        bool can = true;
        for (int j = 0; j < (n - i) / 2; j++) {
            if (s[j] != s[j + (n - i) / 2]) {
                can = false;
                break;
            }
        }
        if (can) {
            cout << (n - i) << '\n';
            exit(0);
        }
    }
    cout << 0 << '\n';
    return 0;
}

