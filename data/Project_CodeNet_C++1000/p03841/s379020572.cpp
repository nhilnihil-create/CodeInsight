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
const int MAXN = 507;

int n;
int x[MAXN];
int a[MAXN*MAXN];
int cc[MAXN];
int ord[MAXN];

void init ();
void input ();
void work ();



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
	
	scanf ( "%d", &n );
	lpi ( i, 1, n ) scanf ( "%d", &x[i] );
}

void work ()
{
	// main work
	
	lpi ( i, 1, n ) ord[i] = i;
	sort ( ord+1, ord+1+n, [] ( int i, int j ) { return x[i] < x[j]; } );
	
	bool flag = false;
	lpi ( i, 1, n ) cc[i] = i - 1;
	
	int nk = 0, ni = 1;
	lpi ( i, 1, n ){
		while ( nk < x[ord[i]] - 1 ){
			while ( !cc[ord[ni]] ){
				++ni;
				if ( ni > n ){
					if ( !flag ) flag = true, ni = 1;
					else{
						printf ( "No\n" );
						return;
					}
				}
			}
			a[++nk] = ord[ni];
			--cc[ord[ni]];
		}
		if ( cc[ord[i]] ){
			printf ( "No\n" );
			return;
		}
		a[++nk] = ord[i];
		cc[ord[i]] = n - ord[i];
		if ( ni == i ) ++ni;
	}
	
	lpi ( i, 1, n ) while ( cc[i] ) a[++nk] = i, --cc[i];
	
	printf ( "Yes\n" );
	lpi ( i, 1, n*n ) printf ( "%d ", a[i] );
	putchar ( '\n' );
}