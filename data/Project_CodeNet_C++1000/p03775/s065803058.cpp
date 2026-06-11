#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)

using int64 = uint64_t;
using namespace std;

int digits(int64 n) {
    int cnt = 0;
    while (n > 0) {
        n /= 10;
        cnt++;
    }
    return cnt;
}

int main() {
    fastIO;

    int64 n;
    cin >> n;

    // left, right
    int64 digit = 100;
    for (int64 l = 1; l * l <= n; l++) {
        if (n % l == 0) {
            int64 r = n / l;
            int64 max_digit = max(digits(l), digits(r));
            digit = min(digit, max_digit);
        }
    }
    cout << digit << endl;
}

