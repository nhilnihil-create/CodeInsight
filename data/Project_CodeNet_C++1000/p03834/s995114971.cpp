#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;

    rep(i, s.size()) {
        if (',' == s.at(i)) {
            s.at(i) = ' ';
        }
    }

    cout << s << endl;

    return 0;
}