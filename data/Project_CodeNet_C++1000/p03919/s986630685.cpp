#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    int h, w;
    cin >> h >> w;

    rep(i, h) {
        rep(j, w) {
            string word;
            cin >> word;
            if (word == "snuke") {
                cout << (char)('A' + j) << (i + 1);
                return 0;
            }
        }
    }
}