#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<typename T>
using vector2d = vector<vector<T>>;

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

int main() {
    i64 N, K;
    cin >> N >> K;
    vector<i64> a(N);
    for(auto &x : a) cin >> x;
    sort(WHOLE(a));
    auto f = [&](int x) -> bool {
        vector<bool> dp[2] = {vector<bool>(K, false), vector<bool>(K, false)};
        dp[0][0] = true;
        for (i64 i = 0; i < N; i++) {
            int b = i & 1;
            for (i64 s = 0; s < K; s++) {
                if(i != x && s - a[i] >= 0) {
                    dp[!b][s] = dp[b][s] | dp[b][s - a[i]];
                } else {
                    dp[!b][s] = dp[b][s];
                }
            }
        }
        bool retval = false;
        for(i64 s = max<i64>(0, K - a[x]); s < K; s++) {
            retval |= dp[N & 1][s];
        }
        return !retval;
    };
    int ans = BinSearch<int>(-1, a.size(), f, false);
    cout << ans + 1 << endl;
    return 0;
}