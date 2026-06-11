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
const int MAXN = 100007;

int n;
int x[MAXN];
int a[MAXN];
int p[MAXN];
int m;
LL K;
int op[MAXN];
int ans[MAXN];
LL ax[MAXN];
bool vis[MAXN];

void init ();
void input ();
void work ();

AR(int) getcyc ( int beg );



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
	scanf ( "%d%lld", &m, &K );
	lpi ( i, 1, m ) scanf ( "%d", &op[i] );
}

void work ()
{
	// main work
	
	lp ( i, 1, n ) a[i] = x[i+1] - x[i];
	
	lp ( i, 1, n ) p[i] = i;
	lpi ( i, 1, m ) swap ( p[op[i]], p[op[i]-1] );
	
	lpi ( i, 1, n ){
		if ( !vis[i] ){
			AR(int) ret = getcyc ( i );
			int len = ret.size ();
			int tms = K % len;
			lp ( i, 0, len ) ans[ret[i]] = ret[(i+tms)%len];
		}
	}
	
	ax[1] = x[1];
	lpi ( i, 2, n ) ax[i] = ax[i-1] + a[ans[i-1]];
	
	lpi ( i, 1, n ) printf ( "%lld\n", ax[i] );
}



AR(int) getcyc ( int beg )
{
	AR(int) ans;
	int now = beg;
	while ( !vis[now] ){
		vis[now] = true;
		ans.PB ( now );
		now = p[now];
	}
	return ans;
}