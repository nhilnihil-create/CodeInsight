#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define mod 1000000007LL
#define IN freopen("C.in","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define DBG pf("Hi\n")
#define i64 long long int
#define eps (1e-8)
#define xx first
#define yy second
#define ln 17
#define off 2

using namespace __gnu_pbds;
using namespace std ;

typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef pair<i64, i64> pii;

#define maxn 300005
#define INF 2000000000
#define alpha 26

i64 f( i64 i , i64 j , i64 l )
{
    i64 ans = 0 ;

    ans += (i/2)*4 ;
    i%=2 ;

    ans += (j/2)*4 ;
    j%=2 ;

    ans += (l/2)*4 ;
    l%= 2 ;

    if(i==1 && j==1 &&l==1) ans += 6 ;

    return ans ;
}

int main()
{
    i64 i , o  , t , j , l , s , z ;

    scanf("%lld %lld %lld %lld %lld %lld %lld",&i,&o,&t,&j,&l,&s,&z) ;

    i64 ans1 = f(i,j,l) , ans2 = 0 ;

    if( i>0 && j>0 && l>0 ) ans2 = f(i-1,j-1,l-1) + 6 ;

    i64 ans = max(ans1,ans2) ;

    ans += o*2 ;

    printf("%lld\n",ans/2) ;

    return 0 ;
}
