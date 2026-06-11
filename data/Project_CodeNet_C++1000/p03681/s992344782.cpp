#include <bits/stdc++.h>
using namespace std;

int main()
{
        long long MOD = 1000000007;

        long long N, M;
        cin >> N >> M;
        int diff = abs(N-M);
        if (diff > 1) {
                cout << 0 << endl;
                exit(0);
        }
        if (N == M) {
                long long ans = 1;
                for (int i = 0; i < N; ++i) {
                        ans = ans * (i+1) % MOD;
                }
                ans = ans * ans % MOD;
                ans = ans * 2 % MOD;
                cout <<  ans << endl;
        }
        else {
                long long ans1 = 1;
                for (int i = 0; i < N; ++i) {
                        ans1 = ans1 * (i+1) % MOD;
                }
                long long ans2 = 1;
                for (int i = 0; i < M; ++i) {
                        ans2 = ans2 * (i+1) % MOD;
                }
                ans1 = ans1 * ans2 % MOD;
                cout << ans1 << endl;
        }

}
