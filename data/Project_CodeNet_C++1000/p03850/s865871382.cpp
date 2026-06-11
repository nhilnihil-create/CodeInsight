#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <cassert>
using namespace std;

#define GET_ARG(a,b,c,F,...) F
#define REP3(i,s,e) for (i = s; i <= e; i++)
#define REP2(i,n) REP3 (i,0,(int)(n)-1)
#define REP(...) GET_ARG (__VA_ARGS__,REP3,REP2) (__VA_ARGS__)
#define RREP3(i,s,e) for (i = s; i >= e; i--)
#define RREP2(i,n) RREP3 (i,(int)(n)-1,0)
#define RREP(...) GET_ARG (__VA_ARGS__,RREP3,RREP2) (__VA_ARGS__)
#define DEBUG(x) cerr << #x ": " << x << endl

typedef long long ll;

const ll INF = 1e15;

ll dp[100001][3];
char op[100000];
int a[100000];

int main(void) {
    int i, n;
    scanf("%d",&n);
    op[0] = '+';
    REP (i,n-1) scanf("%d %c",&a[i],&op[i+1]);
    scanf("%d",&a[n-1]);

    dp[0][1] = dp[0][2] = -INF;
    REP (i,n) {
        if (op[i] == '+') {
            dp[i+1][0] = max({dp[i][0] + a[i],dp[i][1] - a[i],dp[i][2] + a[i]});
            dp[i+1][1] = max(dp[i][1] - a[i],dp[i][2] + a[i]);
            dp[i+1][2] = dp[i][2] + a[i];
        }
        else {
            dp[i+1][0] = max(dp[i][0] - a[i],dp[i][2] - a[i]);
            dp[i+1][1] = max({dp[i][0] - a[i],dp[i][1] + a[i],dp[i][2] - a[i]});
            dp[i+1][2] = dp[i][1] + a[i];
        }
    }
    ll ans = 0;
    REP (i,3) ans = max(ans,dp[n][i]);
    printf("%lld\n",ans);
    return 0;
}
