#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;
using namespace std;

char str[5005];
ll dp[5005][5005];

ll mpow(ll x, ll n){ //x^n(mod M)
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % MOD;
        x = x*x % MOD;
        n = n >> 1;
    }
    return ans;
}

ll minv(ll x){
    return mpow( x, MOD-2 );
}

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);
    scanf("%s", str);
    int m=strlen(str);

    dp[0][0]=1;
    int i,j;
    for(i=0; i<n; i++) {
        for(j=0; j<=n; j++) {
            if(dp[i][j]) {
                dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j]*2)%MOD;
                if(j>0) dp[i+1][j-1]=(dp[i+1][j-1]+dp[i][j])%MOD;
                if(j==0) dp[i+1][j]=(dp[i+1][j]+dp[i][j])%MOD;
            }
        }
    }
    ll ans=(dp[n][m]*minv(mpow(2,m)))%MOD;

    printf("%lld\n", ans);

    return 0;
}
