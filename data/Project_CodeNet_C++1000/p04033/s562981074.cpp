#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
using lint = long int;
using llint = long long int;
using namespace std;

int main() {
    fastIO;
    lint a, b;
    cin >> a >> b;
    if (a == 0 || b == 0 || (a <= 0 && 0 <= b)) {
        cout << "Zero";
    } else if (a < 0) {
        if ((-a + b + 1) % 2 == 0) {
            cout << "Positive";
        } else {
            cout << "Negative";
        }
    } else {
        cout << "Positive";
    }
}
