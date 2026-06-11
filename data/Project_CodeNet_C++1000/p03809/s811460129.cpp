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

struct eT
{
	void setd ( int _u, int _v, int _l )
	{
		u = _u, v = _v, last = _l;
	}
	
	int u, v, last;
}edge[MAXN*2];

int n;
int ke, la[MAXN];
int a[MAXN];

void init ();
void input ();
void work ();

int dfs ( int now, int fa );



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
	lpi ( i, 1, n ) scanf ( "%d", &a[i] );
	INIT ( la, -1 );
	int u, v;
	lp ( i, 1, n ){
		scanf ( "%d%d", &u, &v );
		edge[ke].setd ( u, v, la[u] );
		la[u] = ke++;
		edge[ke].setd ( v, u, la[v] );
		la[v] = ke++;
	}
}

void work ()
{
	// main work
	
	if ( n == 2 ){
		cout << ( ( a[1] == a[2] ) ? "YES" : "NO" ) << endl;
		return;
	}
	
	int rt = -1;
	lpi ( i, 1, n ){
		if ( ~edge[la[i]].last ){
			rt = i;
			break;
		}
	}
	
	cout << ( dfs ( rt, -1 ) ? "NO" : "YES" ) << endl;
}



int dfs ( int now, int fa )
{
	LL sum = 0;
	int v, tv, maxi = 0;
	bool isch = true;
	for ( int i = la[now]; ~i; i = edge[i].last ){
		if ( ( v = edge[i].v ) ^ fa ){
			isch = false;
			tv = dfs ( v, now );
			sum += tv;
			maxi = qmax ( maxi, tv );
		}
	}
	if ( isch ) return a[now];
	LL del = sum - a[now];
//	cerr << now << " " << sum << " " << a[now] << " " << del << endl;
	if ( del < 0 || del > a[now] || del > sum - maxi ){
		cout << "NO" << endl;
		exit ( 0 );
	}
	return a[now] - del;
}