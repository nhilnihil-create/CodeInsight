/*
                ____________    ______________       __
               / _________  /\ /_____   _____/\     / /\
              / /\       / /  \\    /  /\    \ \   / /  \
             / /  \_____/ /   / \__/  /  \____\/  / /   /
            / /   /    / /   /    /  /   /       / /   /
           / /   /    / /   /    /  /   /       / /   /
          / /   /    / /   /    /  /   /       / /   /
         / /___/____/ /   /    /  /   /       / /___/________
        /____________/   /    /__/   /       /______________/\
        \            \  /     \  \  /        \              \ \
         \____________\/       \__\/          \______________\/
           ___       ___               ___    __________
          /  /\     /  /\             /  /\  /_______  /\
         /  /__\___/  /  \           /  /  \ \      /  /  \
        /____    ____/   /          /  /   /  \____/  /   /
        \   /   /\   \  /          /  /   /       /  /   /
         \_/   /  \___\/ ___      /  /   /       /  /   /
          /   /   /     /  /\    /  /   /       /  /   /
         /   /   /     /  /__\__/  /   /       /  /___/____
        /___/   /     /___________/   /       /___________/\
        \   \  /      \           \  /        \           \ \
         \___\/        \___________\/          \___________\/
 
          A FAN OF FIZZYDAVID
 
*/
 
#include<bits/stdc++.h>
 
#define HEAP priority_queue
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define forn(i,l,r) for(int i=(l);i<=(r);i++)
#define nrof(i,r,l) for(int i=(r);i>=(l);i--)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define X first
#define Y second
#define eps 1e-6
#define pi 3.1415926535897932384626433832795
#define orz int
#define yjz main
#define fizzydavid return
#define ak 0
#define la ;
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define FILL(a,b) memset((a),(b),sizeof((a)))
 
using namespace std;
 
typedef long long LL;
typedef double flt;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<LL> vl;
typedef pair<int,LL> pil;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
typedef vector<pil> vil;
typedef vector<pii> vii;
 
const int iinf=1e9+7;
const LL linf=1ll<<60;
const flt dinf=1e10;
 
template <typename T>
inline void scf(T &x)
{
	bool f=0; x=0; char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') { f=1; c=getchar(); }
	while(c>='0' && c<='9') { x=x*10+c-'0'; c=getchar(); }
	if(f) x=-x; return;
}
 
template <typename T1,typename T2>
void scf(T1 &x,T2 &y) { scf(x); return scf(y); }
 
template <typename T1,typename T2,typename T3>
void scf(T1 &x,T2 &y,T3 &z) { scf(x); scf(y); return scf(z); }
 
template <typename T1,typename T2,typename T3,typename T4>
void scf(T1 &x,T2 &y,T3 &z,T4 &w) { scf(x); scf(y); scf(z); return scf(w); }
 
#ifdef ONLINE_JUDGE
#define debug(x,c) ;
#else
#define DEBUG
#define debug(x,c) cerr<<#x<<"="<<x<<c;
#endif
 
//---------------------------head----------------------------
 
const int N = 1e5 + 100;
 
int n;
vi g[N];
int a[N];
 
void dfs(int u, int fa)
{
    if(SZ(g[u]) == 1) return;
    int tot, Max; tot = Max = 0;
    for(int v: g[u]) if(v != fa) dfs(v, u), tot += a[v], Max = max(Max, a[v]);
    if(tot < a[u]){ puts("NO"); exit(0); }
    if(Max > tot - Max && Max > a[u]){ puts("NO"); exit(0); }
    a[u] = tot - (tot - a[u]) * 2;
    if(a[u] < 0){ puts("NO"); exit(0); }
    return;
}
 
orz yjz()
{
    scf(n);
    forn(i, 1 ,n) scf(a[i]);
    rep(i, n - 1)
    {
        int u, v; scf(u, v);
        g[u].pb(v); g[v].pb(u);
    }
    if(n == 2){ puts(a[1] == a[2] ? "YES" : "NO"); fizzydavid ak la }
    int root;
    forn(i, 1, n) if(SZ(g[i]) != 1){ root = i; break; }
    dfs(root, 0);
    puts(a[root] ? "NO" : "YES");
	fizzydavid ak la
}