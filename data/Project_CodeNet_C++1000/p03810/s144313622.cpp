/*input
5
7 8 8 8 8
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
const ll maxn=1000005;
const ll magic=500;

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

int a[maxn];

int main()
{
	IOS;
	int n;
	cin>>n;
	REP(i,n) cin>>a[i];
	if(n==1){
		if(a[0]==1)	cout<<"Second\n";
		else cout<<"First\n";
		return 0;
	}

	int turn=0;
	while(1){
		int cnt=0;
		int id=0;
		REP(i,n){
			if(a[i]%2==0) cnt++;
			else id=i;
		}
		if(cnt%2==1){
			if(turn%2==0) cout<<"First\n";
			else cout<<"Second\n";
			return 0;
		}
		else if(cnt!=n-1||a[id]==1){
			if(turn%2) cout<<"First\n";
			else cout<<"Second\n";
			return 0;
		}
		else{
			REP(i,n) if(a[i]%2) a[i]--;
			int gg=a[0];
			REP(i,n) gg=__gcd(gg,a[i]);
			REP(i,n) a[i]/=gg; 
		}
		turn++;
	}
}
