#include <algorithm>
#include <cstdio>

using namespace std ;

const int N=400 ;

int a[N][N] , w[N] , del[N] ;
int n , m ;
inline int check ( int x )
{
	// printf("Check %d\n",x);
	int i ;
	for ( i=1 ; i<=m ; i++ ) w[i]=0,del[i]=0;
	for ( i=1 ; i<=n ; i++ ) a[i][0]=1,w[a[i][1]]++;
	while ( 1 )
	{
		int mx=0 , pos=0 ;
		for ( i=1 ; i<=m ; i++ ) 
			if ( w[i]>mx ) mx=w[i],pos=i;
		if ( mx<=x ) return 1 ;
		del[pos]=1;
		for ( i=1 ; i<=n ; i++ ) 
			if ( a[i][a[i][0]]==pos ) 
			{
				while ( a[i][0]<=m && del[a[i][a[i][0]]] ) a[i][0]++;
				if ( a[i][0]>m ) return 0 ;
			}
		for ( i=1 ; i<=m ; i++ ) w[i]=0;
		for ( i=1 ; i<=n ; i++ ) w[a[i][a[i][0]]]++;
	}
	return 0 ;
}

int main ()
{
	int i , j ;
	scanf("%d%d",&n,&m);
	for ( i=1 ; i<=n ; i++ ) 
		for ( j=1 ; j<=m ; j++ ) scanf("%d",a[i]+j);
	int l=1 , r=n , mid ;
	for ( mid=(l+r)>>1 ; l<r ; mid=(l+r)>>1 )
		if ( check(mid) ) r=mid;
		else l=mid+1;
	printf("%d\n",l);
	return 0 ;
}