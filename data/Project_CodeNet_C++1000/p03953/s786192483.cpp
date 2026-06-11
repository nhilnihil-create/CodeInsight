/*input
5
0 1 3 6 10
3 10
2 3 4
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
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
	out<<'('<<P.F<<','<<P.S<<')';
	return out;
}

//}}}
const ll maxn=100005;
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
#define int ll
ll a[maxn];
vector<int> v;
int idx[maxn];
bool vis[maxn];
int ans[maxn];

vector<int> OAO;
int32_t main()
{
	IOS;
	int n;
	cin>>n;
	REP(i,n) cin>>a[i];

	ll m,k;
	cin>>m>>k;
	REP(i,n-1) v.pb(i);
	while(m--){
		int tmp;
		cin>>tmp;
		tmp-=2;
		swap(v[tmp],v[tmp+1]);
	}
	REP(i,n-1) idx[v[i]]=i;

	for(int i=0;i<n-1;i++) if(!vis[i]){
		int cur=i;
		OAO.clear();
		while(!vis[cur]){
			OAO.pb(cur);
			vis[cur]=1;
			cur=v[cur];
		}
		REP(i,SZ(OAO)) ans[OAO[i]]=OAO[(i+k)%SZ(OAO)];
	}
	int cur=a[0];

	cout<<cur<<'\n';
	for(int i=0;i<n-1;i++){
		cur+=a[ans[i]+1]-a[ans[i]];
		cout<<cur<<'\n';
	}
	return 0;
}
