/*input
1 1 1
10 10 10
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
const ll maxn=300005;
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

pll v[maxn];

map<ll,ll> mp;

int main(){
	IOS;
	int n,ma,mb;
	cin>>n>>ma>>mb;
	REP(i,n){
		ll a,b,c;
		cin>>a>>b>>c;
		v[i]=MP(a*mb-b*ma,c);
	}

	REP(i,1<<(n/2)) if(i){
		ll val=0, mon=0;
		REP(j,n/2){
			if((i>>j)&1){
				val+=v[j].F;
				mon+=v[j].S;
			}
		}
		if(mp.count(val)){
			mp[val]=min(mp[val],mon);
		}
		else mp[val]=mon;
	}
	// for(auto i:mp) countt<<i<<'\n';
	ll ans=INF;
	REP(i,1<<(n-n/2)){
		ll val=0, mon=0;
		REP(j,n-n/2){
			if((i>>j)&1){
				val+=v[n/2+j].F;
				mon+=v[n/2+j].S;
			}
		}
		if(mp.count(-val)){
			ans=min(ans,mp[-val]+mon);
		}

		if(val==0&&i!=0){
			ans=min(ans,mon);
		}
	}
	if(ans==INF){
		cout<<"-1\n";
	}
	else cout<<ans<<'\n';
	return 0;
}
