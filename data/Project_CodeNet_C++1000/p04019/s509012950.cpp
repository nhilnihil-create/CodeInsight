#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
using lint = long int;
using llint = long long int;
using namespace std;

int main() {
    fastIO;
    string s;
    cin >> s;
    bool direction[4]{false};

    for (auto ch : s) {
        if (ch == 'N') {
            direction[0] = true;
        } else if (ch == 'S') {
            direction[1] = true;
        } else if (ch == 'W') {
            direction[2] = true;
        } else {
            direction[3] = true;
        }
    }

    if (direction[0] == direction[1] && direction[2] == direction[3]) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
