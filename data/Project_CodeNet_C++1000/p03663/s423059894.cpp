#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast<t>(x)
#define AR(t) vector < t >
#define PII pair < int, int >
#define PLL pair < LL, LL >
#define PIL pair < int, LL >
#define PLI pair < LL, int >
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define PRF first
#define PRS second
#define INIT(ar,val) memset ( ar, val, sizeof ( ar ) )
#define lp(loop,start,end) for ( int loop = start; loop < end; ++loop )
#define lpd(loop,start,end) for ( int loop = start; loop > end; --loop )
#define lpi(loop,start,end) for ( int loop = start; loop <= end; ++loop )
#define lpdi(loop,start,end) for ( int loop = start; loop >= end; --loop )
#define qmax(a,b) (((a)>(b))?(a):(b))
#define qmin(a,b) (((a)<(b))?(a):(b))
#define qabs(a) (((a)>=0)?(a):(-(a)))

const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 1e9;
const int MAXL = 10;

void init ();
void input ();
void work ();

bool query ( LL x );
void find ( LL x );



int main()
{
	init();
	input();
	work();
}



void init ()
{
	// Init Everything Here

	ios::sync_with_stdio ( false );
}

void input ()
{
	// input method
}

void work ()
{
	// main work

	int len = -1;
	LL bs = 1;
	lp ( i, 0, MAXL ){
		if ( !query ( bs ) ){
			len = i - 1;
			break;
		}
		bs *= 10;
	}
	if ( len == -1 ){
		bs = 10;
		lp ( i, 0, MAXL ){
			if ( query ( bs - 1 ) ){
				len = i;
				break;
			}
			bs *= 10;
		}
	}

	if ( len == MAXL - 1 ) find ( MAXN );

	int l = 1, r, mid;
	lp ( i, 0, len ) l *= 10;
	r = l * 10 - 1;
	while ( l < r ){
		mid = ( l + r ) >> 1;
		if ( query ( 1LL * mid * MAXN ) ) r = mid;
		else l = mid + 1;
	}

	find ( l );
}



bool query ( LL x )
{
	printf ( "? %lld\n", x );
	fflush ( stdout );
	char in[5];
	scanf ( "%s", in );
	return ( in[0] == 'Y' );
}

void find ( LL x )
{
	printf ( "! %lld\n", x );
	fflush ( stdout );
	exit ( 0 );
}