#include <algorithm>
#include <cstdio>

using namespace std ;

typedef long long LL ;

inline LL solve ( LL a , LL b )
{
	if ( b%a==0 ) return 2*b-a ;
	return solve(b,a%b)+a/b*b*2;
}

int main ()
{
	LL n , x ;
	scanf("%lld%lld",&n,&x);
	if ( 2*x<=n ) printf("%lld\n",n+solve(n-x,x));
	else printf("%lld\n",n+solve(x,n-x));
	return 0 ;
}