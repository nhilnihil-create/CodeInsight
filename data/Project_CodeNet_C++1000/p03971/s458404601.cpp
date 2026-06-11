#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    int n, a, b;
    cin >> n >> a >> b;

    string s;
    cin >> s;

    int passed = 0;
    int oversea = 1;
    rep(idx, n) {
        if (s[idx] == 'a') {
            if (passed < a + b) {
                passed++;
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        } else if (s[idx] == 'b') {
            if (passed < a + b && oversea <= b) {
                passed++;
                oversea++;
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        } else {
            cout << "No\n";
        }
    }
}
