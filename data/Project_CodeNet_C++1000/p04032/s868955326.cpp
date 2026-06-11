#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
    string s; cin >> s;
    int N = s.size();
    rep2(i, 1, N) {
        if (s[i] == s[i-1]) {
            cout << i << " " << i+1;
            return 0;
        }
    }
    for (int i = 0; i+2 < N; i++) {
        if (s[i] == s[i+2]) {
            cout << i+1 << " " << i+3 << endl;
            return 0;
        }
    }
    cout << -1 << " " << -1 << endl;
}
