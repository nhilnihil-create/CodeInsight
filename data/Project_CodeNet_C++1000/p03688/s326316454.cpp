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
#define INF 1000000000000000000LL
#define i64 long long int
#define eps (1e-8)
#define xx first
#define yy second
#define ln 17
#define off 2
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace __gnu_pbds;
using namespace std ;

typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long

#define maxn 1000005

int ans[maxn] ;
pair<int,int> a[maxn] ;

int main()
{
    int n ;

    scanf("%d",&n) ;

    for(int i=1 ; i<=n ; i++)
    {
        scanf("%d",&a[i].xx) ;
        a[i].yy = i ;
    }

    sort( a+1,a+n+1 ) ;

    if( a[n].xx - a[1].xx > 1 )
    {
        printf("No\n") ;
        return 0 ;
    }

    if( a[1].xx == a[n].xx )
    {
        if( a[1].xx==n-1 )
        {
            printf("Yes\n") ;
/*            for(int i=1 ; i<=n ; i++)
            {
                printf("%d",i) ;
                if( i==n ) printf("\n") ;
                else printf(" ") ;
            } */
            return 0 ;
        }

        if( a[1].xx*2 > n )
        {
            printf("No\n") ;
            return 0 ;
        }

        for(int i=1 ; i<=a[1].xx ; i++) ans[i] = i ;
        for(int i=a[1].xx+1 ; i<=n ; i++) ans[i] = ans[i-a[1].xx] ;

        printf("Yes\n") ;
      /*  for(int i=1 ; i<=n ; i++)
        {
            printf("%d",ans[i]) ;
            if( i==n ) printf("\n") ;
            else printf(" ") ;
        } */
        return 0;
    }

    int small = 0 , large = 0 ;

    for(int i=1 ; i<=n ; i++)
    {
        if( a[i].xx == a[1].xx ) small++ ;
        else large++ ;
    }

//    printf("%d\n",small) ;

    if( a[n].xx <= small || (a[n].xx-small)*2 > large )
    {
        printf("No\n") ;
        return 0 ;
    }

    printf("Yes\n") ;
/*
    for(int i=1 ; i<=a[n].xx ; i++) ans[ a[i].yy ] = i ;

    int i=a[n].xx+1 , j=1 ;

    for( ; i<=n ; i++ ) ans[ a[i].yy ] = ans[ a[i- (a[n].xx-small) ].yy ] ;

    for( i=1 ; i<=n ; i++)
    {
        printf("%d",ans[i]) ;
        if( i==n ) printf("\n") ;
        else printf(" ") ;
    } */

    return 0 ;
}
