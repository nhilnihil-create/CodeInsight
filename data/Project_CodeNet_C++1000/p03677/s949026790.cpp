//#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
//#define int long long
typedef long long ll;
typedef float f80;
//#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
//const int mod=998244353;
int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(ll a, ll b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

vi clos[100005];
int open[100005];
void solve() {
	int n,m;
	cin>>n>>m;
	vector<pii> tol;
	int a,b;
	cin>>a;
	fr(i,2,n) {
		cin>>b;
		tol.pb({a,b});
		a=b;
	}
	int inter=0;
	ll sum=0,val=0;
	for(auto i:tol) {
		if(i.fi>i.se) {
			inter++;
			val+=m-i.fi;
			sum+=m-i.fi+i.se;
			clos[i.se].pb(m-i.fi+i.se-1);
		} else {
			sum+=i.se-i.fi;
			clos[i.se].pb(i.se-i.fi-1);
		}
		open[i.fi]++;
		trace(sum,i.fi,i.se,m,val,inter,clos[i.se].back());
	}
	ll ans=val;
	fr(x,1,m-1) {
		for(int j:clos[x])
			val-=j;
		inter-=clos[x].size();
		val+=inter;
		inter+=open[x];
		trace(inter,val);
		ans=max(ans,val);
	}
	cout<<sum-ans<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}
