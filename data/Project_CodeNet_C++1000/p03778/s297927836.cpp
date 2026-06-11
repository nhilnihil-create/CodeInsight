#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int W, a, b;
    cin >> W >> a >> b;

    // 考え方メモ
    // 1, a + W < b -> b - (a + W)
    // 2, b <= a + W && a <= b -> 0
    // 3, b < a -> a - (b + W)

    int distance = 0;
    if (a + W < b) {
        distance = b - (a + W);
    } else if (b < a) {
        distance = a - (b + W);
    } else {
        distance = 0;
    }

    cout << distance << endl;

    return 0;
}