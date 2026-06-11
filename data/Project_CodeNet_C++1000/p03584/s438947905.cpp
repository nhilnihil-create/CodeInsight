#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<typename T> using rev_priority_queue = priority_queue<T, vector<T>, greater<T>>;


int main() {
    i64 N, K;
    cin >> N >> K;
    vector<pair<i64, i64>> X(N);
    for(auto &x : X) {
        cin >> x.first >> x.second;
    }
    auto f = [&](i64 k) -> i64 {
        i64 a = 0, b = 0;
        for(auto &x : X) {
            i64 A, B;
            tie(A, B) = x;
            if ((a | A) & (~k)) {
                continue;
            } else {
                a |= A;
                b += B;
            }
        }
        return b;
    };
    i64 ans = 0;
    for(int i = 32; i >= 0; i--) {
        // i ビット以上が K と一致するような場合
        if (K & (1ll << i)) {
            // iビット目が 1 または 完全一致
            i64 a = 0, b = 0;
            i64 k = K & ( ((1ll << 32) - 1) - ((1ll << (i + 1)) - 1));
            k |= (1ll << i) - 1;
            ans = max(ans, f(k));
        }
    }
    ans = max(ans, f(K));
    cout << ans << endl;
    return 0;
}