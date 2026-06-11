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
	ll ans=0;
	ll cnt=0;
	rep(i,0,n){
		ll a; cin>>a;
		if(a==0){
			ans+=(cnt/2);
			cnt=0;
		}
		cnt+=a;
	}
	ans+=cnt/2;
	cout<<ans<<endl;
	
	return 0;
}