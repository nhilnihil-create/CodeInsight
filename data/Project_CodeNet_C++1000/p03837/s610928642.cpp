/*input
3 3
1 2 1
1 3 1
2 3 3
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
#define eb emplace_back
#define pb push_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (int)(lower_bound(c.begin(),c.end(),x)-c.begin())
#define EL cout<<'\n'
#define BS(a,x) binary_search(ALL(a),x)
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
	out<<'('<<P.F<<','<<P.S<<')';
	return out;
}
template<typename T>
ostream& operator<<(ostream& out,vector<T> V){
	REP(i,SZ(V)) out<<V[i]<<((i!=SZ(V)-1)?" ":"");
	return out;
}
//}}}
const ll maxn=305;
const ll maxlg=20;
const ll INF64=1e18;
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

int dis[maxn][maxn];
vector<pair<pii,int>> edge;

int main(){
	IOS;
	int n,m;
	cin>>n>>m;
	REP(i,n) REP(j,n){
		dis[i][j]=(i==j)?0:INF;
	}
	REP(i,m){
		int u,v,d;
		cin>>u>>v>>d;
		u--;v--;
		edge.eb(MP(u,v),d);
		dis[u][v]=dis[v][u]=d;
	}

	REP(j,n) REP(i,n) REP(k,n){
		dis[i][k]=min(dis[i][k],dis[i][j]+dis[j][k]);
	}
	// REP(i,n) REP(j,n) cout<<dis[i][j]<<" \n"[j==n-1];

	int cnt=0;
	for(auto i:edge){
		if(dis[i.F.F][i.F.S]!=i.S) cnt++;
	}
	cout<<cnt<<'\n';

	return 0;
}
