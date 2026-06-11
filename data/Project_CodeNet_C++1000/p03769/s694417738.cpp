#include<cstdio>
//reference

using namespace std ;

typedef long long ll ;

int a[105] ;
int b[105] ;

int main()
{
    ll n; scanf("%lld",&n);
    n++ ;
    int m = 100 ;
    int p1 = 0 , p2 = 0 ;

    while( n > 1 )
    {
        if( n % 2 == 1)
        {
            a[++p1] = m-- ;
            n -- ;
        }
        else
        {
            b[++p2] = m-- ;
            n = n / 2 ;
        }

    }

    printf("%d\n",2*(p1+p2)) ;

    for ( int i = 1 ; i <= p1 ; i++ )
        printf("%d ",a[i]) ;
    for ( int i = p2 ; i >= 1 ; i-- )
        printf("%d ",b[i]) ;
    for ( int i = 101 - p1 - p2 ; i <= 100 ; i++ )
        printf("%d ",i) ;

    return 0 ;
}
