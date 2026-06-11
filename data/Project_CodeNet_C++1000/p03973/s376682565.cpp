#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define mod 1000000007
#define IN freopen("nocross.in","r",stdin)
#define OUT freopen("nocross.out","w",stdout)
#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define DBG pf("Hi\n")
#define INF 2000000000000000000LL
#define i64 long long int
#define eps (1e-8)
#define xx first
#define yy second
#define LOG 19
#define off 2

using namespace __gnu_pbds;
using namespace std ;

typedef tree< i64, null_type, less< i64 >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define maxn 100005

i64 a[maxn] ;

int main()
{
    int n ;

    scanf("%d",&n) ;

    for(int i=1 ; i<=n ; i++) scanf("%lld",&a[i]) ;

    i64 ans = a[1]-1 ;

    a[1] = 1 ;

    i64 mx = 1 ;

    for(int i=2 ; i<=n ; i++)
    {
        if( a[i] == mx+1 )
        {
            mx++ ;
            continue ;
        }
        else{
            if( a[i]%(mx+1) == 0 )
            {
                ans += ( a[i]/(mx+1) - 1 ) ;
            }
            else ans += ( a[i]/(mx+1) ) ;
        }
    }

    printf("%lld\n",ans) ;

    return 0 ;
}
