#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define xx first
#define yy second
#define i64 long long int
#define MEM(a,x) memset(a,x,sizeof(x))
#define INF 1000000000
#define mod 998244353

using namespace std ;

#define maxn 1000005

int a[maxn] , x[maxn] , mark[maxn] ;

int main()
{
    int i , j , k , l , m , n ;

    scanf("%d",&n) ;

    for(i=1 ; i<=n ; i++) scanf("%d",&x[i]) ;

    for(i=1 ; i<=n ; i++) a[ x[i] ] = i , mark[ x[i] ] = 1 ;

    int last = 1 ;

    for(i=1; i<=n*n ; i++)
    {
        if( a[i]!=0 )
        {
            k = 1 ;
            for(j=last ; k<=a[i]-1 ; j++)
            {
                if( a[j]==0 )
                {
                    a[j] = a[i] ;
                    k++ ;
                }
                if( j>=i )
                {
                    printf("No\n") ;
                    return 0 ;
                }
            }
            last = j ;
        }
    }

//    for(i=1 ; i<=n*n ; i++) printf("%d ",a[i]);
 //   printf("\n") ;

    last = n*n ;

    for(i=n*n ; i>=1 ; i--)
    {
        if(  mark[i] )
        {
            k = a[i]+1 ;
            for(j=last ; k<=n ; j-- )
            {
                if( a[j]==0 )
                {
                    a[j] = a[i] ;
                    k++ ;
                    if( j<=i )
                    {
                        printf("No\n") ;
                        return 0 ;
                    }
                }
            }
            last = j ;
        }
    }

    printf("Yes\n") ;

    for(i=1 ; i<=n*n ; i++) printf("%d ",a[i]) ;

    return 0 ;
}
