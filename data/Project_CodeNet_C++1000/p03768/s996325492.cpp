/*input
7 7
1 2
1 3
1 4
4 5
5 6
5 7
2 3
2
6 1 1
1 2 2
*/
#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define F first
#define S second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define pb push_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#ifdef leowang
#define debug(...) do{\
	fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
	_DO(__VA_ARGS__);\
}while(0)
template<typename I> void _DO(I&&x){cerr<<x<<endl;}
template<typename I,typename...T> void _DO(I&&x,T&&...tail){cerr<<x<<", ";_DO(tail...);}
#else
#define debug(...)
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
	out<<'('<<P.F<<','<<P.S<<')';
	return out;
}
//}}}
const ll maxn=300005;
const ll maxlg=__lg(maxn)+2;
const ll INF64=8000000000000000000LL;
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
const double PI=acos(-1);
//const ll p=880301;
//const ll P=31;

ll mypow(ll a,ll b){
	ll res=1LL;
	while(b){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		
		b>>=1;
	}
	return res;
}

vector<int> edge[maxn];
int a[maxn],d[maxn],c[maxn];

bool vis[maxn][11];
int ans[maxn];

void f(int u,int D,int clr){
	//cout<<u<<' '<<D<<' '<<clr<<'\n';
	if(D<0) return;
	if(ans[u]==-1) ans[u]=clr;
	if(vis[u][D]) return;
	vis[u][D]=1;
	f(u,D-1,clr);
	for(int v:edge[u]) f(v,D-1,clr);
}


int main()
{
	IOS;
	int n,m;
	cin>>n>>m;
	REP(i,n) ans[i]=-1;
	REP(i,m){
		int u,v;
		cin>>u>>v;
		u--;v--;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	int q;
	cin>>q;
	for(int i=q-1;i>=0;i--){
		cin>>a[i]>>d[i]>>c[i];
		a[i]--;
	}
	REP(i,q){
		f(a[i],d[i],c[i]);
	}
	REP(i,n) if(ans[i]==-1) ans[i]=0;
	REP(i,n) cout<<ans[i]<<'\n';
	return 0;
	
}
