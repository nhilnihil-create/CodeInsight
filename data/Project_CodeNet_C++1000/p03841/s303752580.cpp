#include <bits/stdc++.h>
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
const ll maxn=1605;
const ll maxlg=__lg(maxn)+2;
const ll INF64=8000000000000000000LL;
const int INF=2000000000;
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
int N;

struct edge{
	int to,cap,rev;
	edge(int _,int __,int ___):to(_),cap(__),rev(___){}
};

vector<edge> G[maxn];

void add_edge(int u,int v,int c){
	G[u].pb(edge(v,c,SZ(G[v])));
	G[v].pb(edge(u,0,SZ(G[u])-1));
}

int lvl[maxn];
int iter[maxn];

vector<int> q;
int pt;
void bfs(int u){
	REP(i,N) lvl[i]=-1;
	lvl[u]=0;
	q.clear();
	q.pb(u);
	pt=0;
	while(pt<SZ(q)){
		int cur=q[pt++];
		for(edge &e:G[cur]){
			if(lvl[e.to]!=-1||e.cap<=0) continue;
			lvl[e.to]=lvl[cur]+1;
			q.pb(e.to);
		}	}
}
int dfs(int s,int t,int f){
	if(s==t) return f;
	for(int &i=iter[s];i<SZ(G[s]);i++){
		edge &e=G[s][i];
		if(e.cap>0&&lvl[e.to]>lvl[s]){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

int dinic(int s,int t){
	int flow=0;
	while(1){
		bfs(s);
		REP(i,N) iter[i]=0;
		if(lvl[t]==-1) return flow;
		int f;
		while((f=dfs(s,t,INF))>0) flow+=f;
	}
}

int n;
int a[maxn];
vector<pii> v;
int32_t main()
{
	int n;
	cin>>n;
	REP(i,n) cin>>a[i];
	REP(i,n) v.pb(MP(a[i],i));
	N=3*n+3;
	v.pb(MP(0,-1));
	v.pb(MP(n*n+1,-1));
	sort(ALL(v));
	REP(i,SZ(v)-1){
		add_edge(i,n*3+2,v[i+1].F-v[i].F-1);
	}
	for(int i=1;i<SZ(v)-1;i++){
		add_edge(3*n+1,n+i,v[i].S);
		for(int j=0;j<i;j++) add_edge(n+i,j,INF);
		add_edge(3*n+1,n+n+i,n-1-v[i].S);
		for(int j=i;j<=n;j++) add_edge(n+n+i,j,INF);
	}
	if(dinic(3*n+1,3*n+2)!=n*n-n){
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
	for(int i=0;i<=n;i++){
		for(edge &e:G[i]){
			if(n<e.to&&e.to<=3*n){
				int tmp=e.to;
				while(tmp>n) tmp-=n;
				REP(I,e.cap) cout<<v[tmp].S+1<<' ';
			}
		}
		//cout<<'\n';
		if(i<n){
			cout<<v[i+1].S+1<<' ';
		}
	}
	cout<<'\n';
}


