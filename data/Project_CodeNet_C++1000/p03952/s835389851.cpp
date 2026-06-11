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

int a[maxn] , used[maxn] ;

int main()
{
    int n , x ;

    scanf("%d %d",&n,&x) ;

    if(x==1 || x==2*n-1)
    {
        printf("No\n") ;
        return 0 ;
    }

    printf("Yes\n") ;

    if(n==2)
    {
        printf("1\n2\n3\n") ;
        return 0 ;
    }

    if(x==2)
    {
        a[n] = x ;
        a[n-1] = 1 ;
        a[n-2] = 4 ;
        a[n+1] = 3 ;
    }
    else{
        a[n] = x ;
        a[n-1] = x+1 ;
        a[n-2] = x-1 ;
        a[n+1] = x-2 ;
    }

    for(int i=n-2 ; i<=n+1 ; i++) used[ a[i] ]++ ;

    int j = 1 ;

    for(int i=1 ; i<=2*n-1 ; i++)
    {
        if( a[i]!=0 ) continue ;
        while( used[j] ) j++ ;
        a[i] = j ;
        j++ ;
    }

    for(int i=1 ; i<=2*n-1 ; i++)
    {
        printf("%d\n",a[i]) ;
    }

    return 0 ;
}
