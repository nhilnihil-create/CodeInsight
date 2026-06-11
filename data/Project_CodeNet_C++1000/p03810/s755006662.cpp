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

typedef pair<int,int> pi ;

#define maxn 1000005

int a[maxn] ;

int gcd( int a , int b )
{
    if(b==0) return a ;
    return gcd( b, a%b ) ;
}

bool f(int n)
{
    int even = 0 , odd = 0 , idx = -1 ;

    for(int i=1 ; i<=n ; i++)
    {
        if( (a[i]&1) )
        {
            odd++ ;
            idx = i ;
        }
        else even++ ;
    }

    if( even%2==1 ) return true ;
    if( odd > 1 || a[idx] == 1 ) return false ;

    a[idx]-- ;

    int g = a[1] ;

    for(int i=2 ; i<=n ; i++)
    {
        if( a[i]%g !=0 ) g = gcd( g , a[i] ) ;
    }
    for(int i=1 ; i<=n ; i++) a[i] /= g ;

    return !f(n) ;
}

int main()
{
    int i , j , k , l , m , n ;

    scanf("%d",&n) ;

    for(i=1 ; i<=n ; i++) scanf("%d",&a[i]) ;

    if( f(n) ) printf("First\n") ;
    else printf("Second\n") ;

    return 0 ;
}
