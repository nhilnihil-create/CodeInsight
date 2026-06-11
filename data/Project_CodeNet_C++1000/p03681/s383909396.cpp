#include <bits/stdc++.h>
using namespace std;

int main()
{
        long long MOD = 1000000000 + 7;
        int N, M;
        cin >> N >> M;

        long long ans = 1;
        if (N == M) {
                for (int i = 0; i < N; ++i) {
                        ans = ans * (i+1) % MOD;
                }
                ans = ans * ans % MOD;
                ans = ans * 2 % MOD;
        }
        else if ((N-1) == M || N == (M-1)) {
                long long a0 = 1;
                for (int i = 0; i < M; ++i) {
                        a0 = a0 * (i+1) % MOD;
                }
                long long a1 = 1;
                for (int i = 0; i < N; ++i) {
                        a1 = a1 * (i+1) % MOD;
                }
                ans = a0 * a1 % MOD;
        }
        else {
                ans = 0;
        }
        cout << ans << endl;


}
