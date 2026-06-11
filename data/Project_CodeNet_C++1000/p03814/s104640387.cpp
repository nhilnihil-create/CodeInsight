#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    string s;
    cin >> s;

    int a;
    int z;

    rep(i, s.length()) {
        if (s[i] == 'A') {
            a = i;
            break;
        }
    }

    for (int i = s.length(); i > 0; --i) {
        if (s[i] == 'Z') {
            z = i;
            break;
        }
    }
    cout << z - a + 1<< endl;

    return 0;
}