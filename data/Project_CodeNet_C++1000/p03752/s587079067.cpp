#include <bits/stdc++.h>
using namespace std;

const int64_t INF = 1e18;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int64_t> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];
    int64_t ans = INF;
    for(int bit = 0; bit < (1 << (N - 1)); ++bit) {
        if(__builtin_popcount(bit) != K - 1) continue;
        int64_t now = A[0], sum = 0;
        for(int i = 0; i < N - 1; ++i) {
            if(bit & (1 << i)) {
                if(now < A[i + 1]) {
                    now = max(now, A[i + 1]);
                } else {
                    sum += now - A[i + 1] + 1;
                    now++;
                }
            } else {
                now = max(now, A[i + 1]);
            }
        }
        ans = min(ans, sum);
    }
    cout << ans << '\n';
    return 0;
}
