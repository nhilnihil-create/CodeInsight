#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int match = n;
    for (int i = 0; i < n; i++) {
        string ss = s.substr(i);
        string tt = t.substr(0, n-i);

        if (ss == tt) break;
        match--;
    }
    cout << n*2-match << endl;
}