/*
 * 	Roses are red
 * 		Violets are blue
 * 			I cried
 * 				And so did you
 */
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define endl '\n'
#endif
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
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=1e9;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

int fact[200005],ifact[200005];
int powm(int a, int b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
inline int ncr(int n, int r) {
	return (((fact[n]*ifact[r])%mod)*ifact[n-r])%mod;
}
void solve() {
	fact[0]=1;
	fr(i,1,200001)
		fact[i]=(fact[i-1]*i)%mod;
	ifact[200001]=powm(fact[200001],mod-2);
	for(int i=200000; i>=0; i--)
		ifact[i]=(ifact[i+1]*(i+1))%mod;
	int h,w,a,b;
	cin>>h>>w>>a>>b;
	int ans=ncr(h+w-2,w-1);
	trace(ans);
	for(int i=0; i<a; i++) {
		ans=(ans-(ncr(h-i+b-2,b-1)*ncr(i+w-b-1,i)))%mod;
	}
	if(ans<0)
		ans+=mod;
	cout<<ans<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}
