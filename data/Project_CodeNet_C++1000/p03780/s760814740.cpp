//dp[x+1][y] := x枚まで使った時に総和をyにできるか?
//dp[0][0] = 0 (0 <= i <= N)
//もしdp[i][j] = trueなら、dp[i+1][j] = true; dp[i+1][j + a[i]] = true;
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i,n) for(int i = 0; i < (int)n; ++i)

const int MAX_N = 5010;
const int MAX_K = 5010;
ll a[MAX_N];
int N; ll K;
bool dp[MAX_N][MAX_K];

bool need(int p) { //p枚目(0-indexed)のカードは必要かどうか
    REP(i, N+1) REP(j, K) dp[i][j] = false;
    dp[0][0] = true;
    REP(i, N){
        if(i == p) { 
            REP(j, K) dp[i+1][j] = dp[i][j];
            continue;
        }
        else {
            for(ll j = 0; j < K; ++j) if(dp[i][j]) {
                dp[i+1][j] = true;
                if(j + a[i] < K) dp[i+1][j + a[i]] = true;
            }
        }
    }
    
    for(int i = max(0LL, K - a[p]); i < K; ++i) if(dp[N][i]) return true;
    return false;
}

int main()
{
    scanf("%d %lld", &N, &K);
    REP(i, N) scanf("%lld", &a[i]);
    sort(a, a + N);
    int low = 0, high = N-1;
    while(high - low > 1) {
        int mid = (high + low)/2;
        if(need(mid)) high = mid;
        else          low  = mid;
    }
    if(!need(high)) printf("%d\n", high + 1);
    else if(need(low)) printf("0\n");
    else printf("%d\n", low + 1);
    return 0;
}