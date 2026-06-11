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
	int n; cin>>n;
	vl a(n),b(n);
	ll cnt=0;
	rep(i,0,n)cin>>a[i]>>b[i];
	for(ll i=n-1;i>=0;--i){
		a[i]+=cnt;
		if(a[i]%b[i]==0)continue;
		ll add=b[i]-(a[i]%b[i])%b[i];
	//	cout<<i<<" "<<a[i]<<" "<<add<<endl;
		cnt+=add;
	}
	cout<<cnt<<endl;
	return 0;
}