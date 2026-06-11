#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define MOD 1000000007
#define MP make_pair
#define PB push_back
typedef long long ll;

int N;
ll dp[2200200], cum, tot;

int main () {
        scanf("%d", &N);
        dp[0] = 1ll;
        fo(i, 1, N+1) {
                if (i-3 >= 0) {
                        cum += dp[i-3];
                        if (cum >= MOD) cum -= MOD;
                }
                dp[i] = cum + dp[i-1];
                if (dp[i] >= MOD) dp[i] -= MOD;
        }
        //fo(i, 0, N+1) printf("dp %d %lld\n", i, dp[i]);

        //if all ones:
        tot = 1ll;
        //now force self to have non-1 before infinity
        fo(i, 0, N) {
                //can put shit here before final
                //can put 2... N
                //with values 3... N+1
                //and at least has to get to N
                //some number ... then go infinity
                ll a = dp[i] * (N-1) % MOD;
                if (i < N-1) a = a * N % MOD;
                //printf("%d: %lld %lld\n", i, dp[i], a);
                tot = (tot + a) % MOD;
        }

        printf("%lld\n", tot);
        return 0;
}

