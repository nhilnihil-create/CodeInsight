#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b

signed main(){
	int n,m; cin>>n>>m;
	vl v(n,1);
	vector<bool> ok(n);
	ok[0]=true;
	ll cnt=0;
	rep(i,0,m){
		ll a,b; cin>>a>>b;
		--a,--b;
		if(ok[a])ok[b]=true;
		v[a]--; v[b]++;
		if(v[a]==0)ok[a]=0;
	}
	rep(i,0,n)cnt+=ok[i];
	cout<<cnt<<endl;
	
	return 0;
}