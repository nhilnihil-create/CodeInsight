#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    int N, K; cin >> N >> K;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    auto doit = [&](int mask) {
        Int ans = 0;
        for (int i = 0; i < N; i++) {
            if ((A[i] | mask) == mask) {
                ans += B[i];
            }
        }
        return ans;
    };
    Int ans = doit(K);
    for (int i = 0; i < 30; i++) {
        int mask = K;
        if (K & (1 << i)) {
            mask &= ~(1 << i);
            mask |= (1 << i) - 1;
            ans = max(ans, doit(mask));
        }
    }
    cout << ans << '\n';
    return 0;
}