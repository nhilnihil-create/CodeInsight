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
#define debug(x) ;
#else
#define DEBUG
#define debug(x) cerr<<#x<<"="<<x<<endl;
#endif

//---------------------------head----------------------------

const int N=1e5+100;

int n;
LL ans,a[N],sum[N],calc[N];
bool typ[N];
int nxt[N];
LL b[N];

orz yjz()
{
    scf(n);
    scf(a[1]); sum[1]=a[1]; ans=a[1]; calc[1]=a[1];
    forn(i,2,n)
    {
        char c=getchar();
        while(c!='+' && c!='-') c=getchar();
        if(c=='-') typ[i]=1;
        scf(a[i]);
        sum[i]=sum[i-1]+a[i];
        if(typ[i]) ans-=a[i];
        else ans+=a[i];
        calc[i]=ans;
    }

    int rem=n+1;
    nrof(i,n,1) if(typ[i])
    {
        nxt[i]=rem;
        rem=i-1;
        b[i]=sum[nxt[i]]-sum[i];
    }

    forn(i,1,n) if(typ[i] && nxt[i]<=n)
    {
        LL tmp=calc[i-1]+sum[n]-sum[nxt[i]]-b[i]-a[i];
        #ifdef DEBUG
        cerr<<i<<' '<<calc[i-1]<<' '<<sum[n]<<' '<<sum[nxt[i]]<<' '<<b[i]<<' '<<a[i]<<' '<<tmp<<endl;
        #endif // DEBUG
        if(tmp>ans) ans=tmp;
    }

    printf("%lld\n",ans);
    fizzydavid ak la
}
