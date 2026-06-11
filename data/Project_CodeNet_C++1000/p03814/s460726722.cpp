#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    int a = 0, z = 0;
    rep(i, n) {
        if (s[i] == 'A') {
            a = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'Z') {
            z = i;
            break;
        }
    }

    cout << z - a + 1 << endl;
    return 0;
}
