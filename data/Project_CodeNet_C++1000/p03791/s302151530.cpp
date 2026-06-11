#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
using namespace std ;	int n ;
int a[MAXN], f[MAXN] ;

int main() {
	scanf("%d",&n) ;
	for (int i=1; i<=n; ++i)	scanf("%d",a+i) ;
	int mx = -1 ;
	for (int i=1; i<=n; ++i) {
		if ( a[i] >= mx + 2 )
			f[i] = f[i-1] + 1, ++++mx ;	
		else	f[i] = f[i-1] ;
	}

	long long ans = 1 ;
	for (int i=1; i<=n; ++i) {
		int k = i - 1 - f[i-1] ;
		if ( k <= 0 )	( ans *= i ) %= MOD ;
		else	( ans *= ( i - k ) ) %= MOD  ;
	}
	
	printf("%lld\n",ans) ;

	return 0 ;
}
