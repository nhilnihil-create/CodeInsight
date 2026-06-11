/*input
5 1 5
1000000000000000 999999999999999 999999999999998 999999999999997 999999999999996
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
const ll maxn=105;
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

pll av=MP(0,1);
ll a[maxn];

ll C[maxn][maxn];

int main(){
	IOS;
	int n,A,B;
	cin>>n>>A>>B;
	REP(i,n) cin>>a[i];


	REP(i,55) REP(j,i+1){
		if(j==0||j==i) C[i][j]=1;
		else C[i][j]=C[i-1][j]+C[i-1][j-1];
	}

	sort(a,a+n,greater<ll>());

	for(int len=A;len<=B;len++){
		ll sum=0;
		REP(i,len) sum+=a[i];
		if(av.F*len<av.S*sum){
			av=MP(sum,len);
		}
	}
	ll ans=0;
	for(int len=A;len<=B;len++){
		vector<ll> v;
		ll sum=0;
		REP(i,len) sum+=a[i],v.pb(a[i]);
		if(av.F*len==av.S*sum){
			reverse(ALL(v));
			while(v.back()!=v[0]) v.pop_back();

			int cnt=0;
			REP(i,n) if(a[i]==v[0]) cnt++;

			ans+=C[cnt][SZ(v)];
		}
	}
	cout<<fixed<<setprecision(12)<<(double)av.F/av.S<<'\n';
	cout<<ans<<'\n';

	return 0;
}
