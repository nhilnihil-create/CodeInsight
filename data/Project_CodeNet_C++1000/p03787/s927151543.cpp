// tzl ak IOI! 
 
#include<bits/stdc++.h>
 
#define HEAP priority_queue
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define per(i, n) for(int i = (n) - 1; i >= 0 ; --i)
#define forn(i, l, r) for(int i = (l); i <= (r); ++i)
#define nrof(i, r, l) for(int i = (r); i >= (l); --i)
#define FOR(a, b) for(auto (a): (b))
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define X first
#define Y second
#define eps 1e-6
#define pi 3.1415926535897932384626433832795
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(), x.end()
#define FILL(a, b) memset((a), (b), sizeof((a)))
#define MCPY(a, b) memcpy((a), (b), sizeof((b)))
 
using namespace std;
 
typedef long long LL;
typedef double flt;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef pair<int,int> pii;
typedef pair<int,LL> pil;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
typedef vector<pil> vil;
typedef vector<pii> vii;
typedef vector<pli> vli;
typedef vector<pll> vll;
 
const int iinf = 1e9 + 7;
const LL linf = 1ll << 60;
const flt dinf = 1e60;
 
template <typename T>
inline void scf(T &x)
{
	bool f = 0; x = 0; char c = getchar();
	while((c < '0' || c > '9') && c != '-') c = getchar();
	if(c == '-') { f = 1; c = getchar(); }
	while(c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
	if(f) x = -x; return;
}
 
template <typename T1, typename T2>
void scf(T1 &x, T2 &y) { scf(x); return scf(y); }
 
template <typename T1, typename T2, typename T3>
void scf(T1 &x, T2 &y, T3 &z) { scf(x); scf(y); return scf(z); }
 
template <typename T1, typename T2, typename T3, typename T4>
void scf(T1 &x, T2 &y, T3 &z, T4 &w) { scf(x); scf(y); scf(z); return scf(w); }
 
inline char mygetchar(){ char c = getchar(); while(c == ' ' || c == '\n') c = getchar(); return c; }
 
template <typename T>
void chkmax(T &x, const T &y){ if(y > x) x = y; return; }
 
template <typename T>
void chkmin(T &x, const T &y){ if(y < x) x = y; return; }
 
#ifdef ONLINE_JUDGE
#define debug(x,c) ;
#else
#define DEBUG
#define debug(x,c) cerr<<#x<<"="<<x<<c;
#endif
 
//---------------------------head----------------------------
 
const int N = 2e5 + 100;
 
int n, m;
int par[N];
int deg[N];
 
int F(int u){ return u == par[u] ? u : par[u] = F(par[u]); }
void UN(int u, int v){ debug(u, '\t') debug(v, '\n') par[F(u)] = F(v); }
 
void TZL()
{
	scf(n, m);
	rep(i, n + n) par[i] = i;
	rep(i, m)
	{
		int u, v;
		scf(u, v);
		u--; v--;
		deg[u]++;
		deg[v]++;
		u <<= 1;
		v <<= 1;
		UN(u, v | 1);
		UN(u | 1, v);
	}
	return;
}
 
void RANK1()
{
	LL cnt0, cnt1, ans;
	cnt0 = cnt1 = 0;
	rep(i, n + n) if(deg[i >> 1] && F(i) == i)
	{
		if(F(i) == F(i ^ 1)) cnt1++;
		else cnt0++;
	}
	ans = cnt0 * cnt0 / 2 + cnt1 * cnt1 + cnt0 * cnt1;
	debug(ans, '\n')
	ans += 1ll * n * n;
	for(int i = n - 1; i >= 0; --i) if(!deg[i]) n--;
	ans -= 1ll * n * n;
	printf("%lld\n", ans);
	return;
}
 
#define tzl int
#define ak main
#define IOI ()
tzl ak IOI
{
#undef tzl
#undef ak
#undef IOI
 
	TZL();
	RANK1();
 
#define tzl return
#define caisi 0
#define myy ;
	tzl caisi myy
#undef tzl
#undef caisi
#undef myy
}