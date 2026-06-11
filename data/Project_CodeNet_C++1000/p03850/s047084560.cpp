#include <cstdio>
#include <algorithm>
using namespace std;
using ll = long long int;
const ll INF = 1LL << 60;

ll N, A[100010], dp[100010][3];
char op[100010];

int main() {
    scanf("%lld", &N);
    for(int i=0; i<N; i++) {
        if(i+1 != N) {
            scanf(" %lld %c", &A[i], &op[i]);
        }
        else {
            scanf(" %lld", &A[i]);
        }
    }

    fill(dp[0], dp[100010], -INF);
    dp[0][0] = 0;
    for(int i=0; i<N; i++) {
        for(int k=0; k<3; k++) {
            if(dp[i][k] == -INF) continue;
            int ni = i+1, nk = k;
            if(i > 0 && op[i-1] == '-') nk++;
            if(nk == 3) nk -= 2;
            ll nval = dp[i][k] + A[i] * (nk % 2 ? -1 : 1);
            for(; nk>=0; nk--) {
                dp[ni][nk] = max(dp[ni][nk], nval);
            }
        }
    }
    /*
    for(int i=0; i<=N; i++) {
        for(int k=0; k<3; k++) {
            printf("dp[%d][%d] = %lld\n", i, k, dp[i][k]);
        }
    }
    */
    printf("%lld\n", dp[N][0]);
    return 0;
}