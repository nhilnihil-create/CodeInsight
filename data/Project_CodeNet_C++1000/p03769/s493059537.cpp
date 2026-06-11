#include <stdio.h>
#include <algorithm>

using namespace std;

struct node {
	long long a , b , c , d;
	long long val;
} s[1200000];
long long cnt;
long long n;
long long C[111][111];
long long ans;
long long out[1200] , tot , num;
bool cmp ( node x1 , node x2 ) {
	return x1.val < x2.val;
}
void add ( long long a , long long b , long long c , long long d ) {
	long long i;
	for ( i = 1 ; i <= a ; i++ )
		out[++tot] = num + 1;
	for ( i = 1 ; i <= b ; i++ )
		out[++tot] = num + 2;
	for ( i = 1 ; i <= c ; i++ )
		out[++tot] = num + 1;
	for ( i = 1 ; i <= d ; i++ )
		out[++tot] = num + 2;
	num += 2;
}
long long get ( long long a , long long b , long long c , long long d ) {
	long long i , j;
	long long ret = 0 , t1 , t2 , t3;
	double x1 , x2 , x3 , x4;
	ret += (1ll<<(a+c-1)) - 1;
	ret += (1ll<<(b+d-1)) - 1;
	if ( ret > 1000000000000ll ) return -1;
	for ( i = 1 ; i <= a && i <= c ; i++ ) {
		for ( j = 1 ; j <= b && j <= d ; j++ ) {
			x1 = C[a][i]; x2 = C[b][j]; x3 = C[c][i]; x4 = C[d][j];
			if ( x1*x2*x3*x4 > 1e12 ) return -1;
			t1 = C[a][i] * C[b][j];
			t1 = t1 * C[c][i];
			t1 = t1 * C[d][j];
			ret += t1;
		}
	}
	return ret;
}
void work () {
	long long i , j , k , l , t;
	scanf ( "%lld" , &n );
	C[0][0] = 1;
	for ( i = 1 ; i <= 50 ; i++ ) {
		C[i][0] = 1;
		for ( j = 1 ; j <= i ; j++ ) {
			C[i][j] = C[i-1][j-1] + C[i-1][j];
			//printf ( "%lld " , C[i][j] );
		}
		//printf ( "\n" );
	}
	//i = 12;
	//printf ( "%lld\n" , get(i,i,i,i) );
	for ( i = 1 ; i <= 20 ; i++ ) {
		for ( j = 1 ; j <= 20 ; j++ ) {
			for ( k = 1 ; k <= 20 ; k++ ) {
				for ( l = 1 ; l <= 20 ; l++ ) {
					t = get(i,j,k,l);
					if ( t == -1 ) continue;
					cnt++;
					s[cnt].a = i;
					s[cnt].b = j;
					s[cnt].c = k;
					s[cnt].d = l;
					s[cnt].val = t;
					//printf ( "%d %d %d %d %lld\n" , i , j , k , l , get ( i , j , k , l ) );
				}
			}
		}
	}
	sort ( s + 1 , s + 1 + cnt , cmp );
	for ( i = cnt ; i >= 1 ; i-- ) {
		if ( s[i].val <= n ) {
			n -= s[i].val;
			ans += s[i].a+s[i].b+s[i].c+s[i].d;
			add ( s[i].a , s[i].b , s[i].c , s[i].d );
		}
	}
	//printf ( "%lld %lld\n" , n , ans );
	while ( n ) {
		out[++ans] = num + 1;
		out[++ans] = num + 1;
		num++;
		n--;
	}
	printf ( "%lld\n" , ans );
	for ( i = 1 ; i <= ans ; i++ ) {
		printf ( "%lld%c" , out[i] , i==ans?'\n':' ' );
	}
}
int main () {
	work ();
	return 0;
}
