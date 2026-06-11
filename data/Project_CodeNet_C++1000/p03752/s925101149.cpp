#include <bits/stdc++.h>
using namespace std;

const int64_t INF = 1e18;

int main() {
    int N, K; cin >> N >> K;
    vector<int64_t> A(N);
    K--;
    for(auto &a : A) cin >> a;
    int64_t ans = INF;
    for(int bit = 0; bit < (1 << (N - 1)); ++bit) {
        if(__builtin_popcount(bit) != K) continue;
        int64_t now = A[0], cost = 0;
        for(int i = 1; i < N; ++i) {
            if(bit & (1 << (i - 1))) {
                int64_t dif = A[i] - now;
                if(dif > 0) {
                    now = A[i];
                } else {
                    cost += -dif + 1;
                    now = A[i] - dif + 1;
                }
            } else {
                now = max(now, A[i]);
            }
        }
        ans = min(ans, cost);
    }
    cout << ans << '\n';
    return 0;
}
