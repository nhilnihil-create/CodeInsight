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
const int MAXM = 400007;

struct eT
{
	int setd ( int _u, int _v, int _l )
	{
		u = _u, v = _v, last = _l;
	}
	
	int u, v, last;
}edge[MAXM];

int n, m;
int ke, la[MAXN];
int c[MAXN];
int c0, c1, c2;

void init ();
void input ();
void work ();

bool dfs ( int now, int nc );



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
	
	scanf ( "%d%d", &n, &m );
	int u, v;
	ke = 0;
	INIT ( la, -1 );
	lp ( i, 0, m ){
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
	
	INIT ( c, -1 );
	lpi ( i, 1, n ){
		if ( c[i] == -1 ){
			if ( la[i] == -1 ) ++c0;   // Single vertex
			else if ( dfs ( i, 0 ) ) ++c2;   // Bipartite
			else ++c1;   // Non-bipartite
		}
	}
	
	cout << SC ( LL, c1 + c2 ) * ( c1 + c2 ) + SC ( LL, c2 ) * c2 + SC ( LL, c0 ) * 2 * n - SC ( LL, c0 ) * c0 << endl;
}



bool dfs ( int now, int nc )
{
	if ( ~c[now] ) return c[now] == nc;
	c[now] = nc;
	
	bool flag = true;
	for ( int i = la[now]; ~i; i = edge[i].last ) flag &= dfs ( edge[i].v, nc ^ 1 );
	
	return flag;
}