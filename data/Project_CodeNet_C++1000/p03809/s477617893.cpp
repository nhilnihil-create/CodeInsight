/*input
6
3 2 2 2 2 2
1 2
2 3
1 4
1 5
4 6
*/
#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
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
const ld PI=acos(-1);
const ld eps=1e-9;
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
int a[maxn];
int up[maxn];
bool vis[maxn];
vector<int> edge[maxn];
int leaf=0;
void dfs(int u){
	// cout<<u<<'\n';
	vis[u]=1;
	ll sum=0;
	int mx=0;
	bool isleaf=1;
	for(int v:edge[u]) if(!vis[v]){
		isleaf=0;
		dfs(v);
		sum+=up[v];
		mx=max(mx,up[v]);
	}
	if(isleaf){
		up[u]=a[u];
		return;
	}
	if(sum<a[u]){
		cout<<"NO\n";
		exit(0);
	}
	if(a[u]+a[u]<sum){
		cout<<"NO\n";
		exit(0);
	}
	if(mx>a[u]){
		cout<<"NO\n";
		exit(0);
	}
	up[u]=sum-2*(sum-a[u]);
	// cout<<u<<' '<<up[u]<<'\n';
	if(u==leaf){
		if(up[u]==a[u]) cout<<"YES\n";
		else cout<<"NO\n";
		exit(0);
	}
}

int main(){
	IOS;
	int n;
	cin>>n;
	REP(i,n) cin>>a[i];
	REP(i,n-1){
		int u,v;
		cin>>u>>v;
		u--;v--;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	while(SZ(edge[leaf])!=1) leaf++;
	dfs(leaf);
	return 0;
}
