#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;

template <typename X>
X BinSearch(X left, X right, function<bool(X)> judge, bool lower = true, X eps = 1) {
    while (right - left > eps) {
        X mid = (right + left) / 2;
        if (judge(mid) == lower) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return lower ? right : left;
}

int main() {
    i64 X;
    cin >> X;
    cout << BinSearch<i64>(0, X + 2, [&](i64 y) -> bool {
        return y * (y + 1) >= 2 * X;
    }) << endl;
    return 0;
}