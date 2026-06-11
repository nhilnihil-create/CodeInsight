#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        ll MOD = 1000000007;

        ll N, M; cin >> N >> M;
        if (abs(N-M) > 1) {
                cout << 0 << endl;
        }
        else {
                if (N == M) {
                        ll ans = 1;
                        for (int i = 0; i < N; ++i) {
                                ans = ans * (i+1) % MOD;
                        }
                        ans = ans * ans % MOD;
                        ans = ans * 2 % MOD;
                        cout << ans << endl;
                }
                else {
                        ll ans1 = 1;
                        for (int i = 0; i < N; ++i) {
                                ans1 = ans1 * (i+1) % MOD;
                        }
                        ll ans2 = 1;
                        for (int i = 0; i < M; ++i) {
                                ans2 = ans2 * (i+1) % MOD;
                        }
                        ans1 = ans1 * ans2 % MOD;
                        cout << ans1 << endl;
                }
        }
}
