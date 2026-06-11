/*input
6 5
1 2
3 2
4 2
1 6
5 6
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
bool vis[maxn];
vector<int> edge[maxn];

int dfs(int u,int d){
	vis[u]=1;
	int ret=1;
	if(d==0) return ret;
	for(int v:edge[u]) if(!vis[v]) ret+=dfs(v,d-1);
	return ret;
}

int main(){
	IOS;
	int n,k;
	cin>>n>>k;
	REP(i,n-1){
		int u,v;
		cin>>u>>v;
		u--;v--;
		edge[u].pb(v);
		edge[v].pb(u);
	}

	int ans=0;

	if(k%2==0){
		REP(i,n){
			fill(vis,vis+n,0);
			ans=max(ans,dfs(i,k/2));
		}
	}
	else{
		REP(i,n) for(int j:edge[i]) if(i<j){
			// cout<<i<<' '<<j<<'\n';
			fill(vis,vis+n,0);
			vis[i]=1;
			int cur=dfs(j,k/2);
			// cout<<cur<<'\n';
			vis[i]=0;
			cur+=dfs(i,k/2);
			// cout<<cur<<'\n';
			ans=max(ans,cur);
		}
	}
	cout<<n-ans<<'\n';
	return 0;
}
