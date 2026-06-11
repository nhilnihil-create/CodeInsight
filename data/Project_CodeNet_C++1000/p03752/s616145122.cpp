
#include <bits/stdc++.h>
using namespace std;

int next_combination(int sub) {
    int x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}

int main() {

    int n, k;
    cin >> n >> k;
    long long a[15];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // combinationループ。NからKをとる通り数で調べる。
    long long minCost = LLONG_MAX;
    for (int bit = (1 << k) - 1; bit < (1 << n); bit = next_combination(bit)) {
        // bitが立っている位置に対して、建物が見えるようにする時のコストを調べ、その最大値を取得する。
        long long maxHeight = 0;
        long long cost = 0;
        for (int i = 0; i < n; i++) {
            long long upHeight = 0;
            if (bit & (1 << i)) {
                upHeight = std::max(0ll, maxHeight + 1 - a[i]);
            }
            cost += upHeight;
            maxHeight = std::max(maxHeight, a[i] + upHeight);
        }
        minCost = std::min(minCost, cost);
    }
    cout << minCost << endl;

}