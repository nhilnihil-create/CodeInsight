#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define mod 1000000007LL
#define maxn 100005
#define IN freopen("C.in","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define DBG pf("Hi\n")
#define INF 1000000000
#define i64 long long int
#define eps (1e-8)
#define xx first
#define yy second
#define ln 17
#define off 2

using namespace __gnu_pbds;
using namespace std ;

typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef pair<int, int> pi;

#define maxn 1000005

i64 dp[maxn] ;

int main()
{
    i64 i , j , k , l , m , n ;

    i64 ret = 0LL ;

    dp[0] = 1LL ;
    for(i64 i =1 ; i<=1000000 ; i++)
    {
        ret =(ret+dp[i-1])%mod ;
        dp[i] = ret ;
        if( i>=2 ) dp[i] = (dp[i]-dp[i-2])%mod ;
    }

    scanf("%lld",&n) ;

    i64 ans = dp[n] ;
    for(i=0 ; i<n ; i++)
    {
        if( i==n-1 ) ans = ( ans + dp[i]*(n-1) )%mod ;
        else ans = ( ans + dp[i]*( ( i+1 + (n-1)*(n-1))%mod  ) )%mod ;
    }

    printf("%lld\n", (ans%mod+ mod)%mod ) ;

    return 0 ;
}
