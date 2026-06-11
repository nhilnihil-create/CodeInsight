#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;

// 二分探索（改）
// judge を満たすような下限を求める
// left:[X] 定義域の下限
// right:[X] 定義域の上限
// judge:[X -> bool] X を評価する関数
// lower:[bool] falseにすると代わりに上限を求める
// eps:[X] 終了距離
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

int64_t divceil(int64_t a, int64_t b) {
    return a / b + (a > 0 && a % b ? 1 : 0);
}

// O(N log(max(h_i)))
int main() {
    i64 N, A, B;
    cin >> N >> A >> B;
    vector<i64> h(N);
    for(auto &x : h) cin >> x;
    cout << BinSearch<i64>(0, 1e9 + 1, [&](i64 y) -> bool {
        i64 z = 0;
        for(int i = 0; i < N; i++) {
            if(h[i] < B * y) continue;
            z += divceil(h[i] - B * y, A - B);
        }
        return z <= y;
    }, true) << endl;
    return 0;
}