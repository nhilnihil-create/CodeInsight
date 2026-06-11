/*input
2
1 2 3
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
vector<int> v;

bool check(){
	int n=(SZ(v))/2;

	int idx=-1;
	for(int i=1;i<SZ(v)-1;i++){
		if(v[i]!=v[i+1]&&v[i]!=v[i-1]) continue;
		if(abs(i-n)<abs(idx-n)) idx=i;
	}
	if(idx==-1){
		return v[0];
	}
	return v[idx];
}

int a[maxn];
int main()
{
	IOS;
	int n;
	cin>>n;
	REP(i,n+n-1) cin>>a[i];

	int l=1,r=2*n;
	while(l!=r-1){
		int mid=(l+r)/2;
		v.clear();
		REP(i,n+n-1) v.pb((a[i]<mid));
		// REP(i,SZ(v)) cout<<v[i]<<" \n"[i==SZ(v)-1];
		if(check()) r=mid;
		else l=mid;
		// cout<<check()<<'\n';
	}
	cout<<l<<'\n';
	return 0;
}
