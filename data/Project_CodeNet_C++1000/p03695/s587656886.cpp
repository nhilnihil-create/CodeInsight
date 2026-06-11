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
	ll n; cin>>n;
	map<ll,ll> mp;
	ll cnt=0;
	rep(i,0,n){
		int a; cin>>a;
		if(a<400)mp[1]++;
		else if(a<800)mp[2]++;
		else if(a<1200)mp[3]++;
		else if(a<1600)mp[4]++;
		else if(a<2000)mp[5]++;
		else if(a<2400)mp[6]++;
		else if(a<2800)mp[7]++;
		else if(a<3200)mp[8]++;
		else cnt++;
	}
	cout<<(mp.size()==0 ? 1:mp.size())<<" "<<mp.size()+cnt<<endl;
	return 0;
}