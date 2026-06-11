#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int left, right;
    if (A < C) {  // 大きい数を左端
        left = C;
    } else {
        left = A;
    }
    if (B < D) {  // 小さい数を右端
        right = B;
    } else {
        right = D;
    }

    int ans = 0;
    if (right - left > 0) {
        ans = right - left;
    }

    cout << ans << endl;

    return 0;
}