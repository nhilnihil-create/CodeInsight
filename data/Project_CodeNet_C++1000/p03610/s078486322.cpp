#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    string s;
    cin >> s;

    rep(i, s.size()) {
        if (i % 2 == 0) {
            cout << s.at(i);
        }
    }

    cout << endl;

    return 0;
}