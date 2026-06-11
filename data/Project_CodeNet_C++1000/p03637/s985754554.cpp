#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using mti = vector<vector<int>>;
using vl = vector<ll>;
using mtl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define n_p(v) next_permutation(v.begin(),v.end())
#define to_ll(b) stoll(b)
#define MOD 1000000007
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp

signed main(){
	int n; cin>>n;
	map<ll,ll> mp;
	//vl vec(n);
	rep(i,0,n){
		ll a; cin>>a;
		if(a%4==0){
			mp[4]++;
		}
		else if(a%2==0){
			mp[2]++;
		}
		else mp[1]++;
		
	}
	string ans="No";
	ll b=mp[2];
	b/=2;
	
	if(n-1<=(mp[4]+b)*2) ans="Yes";
	if(mp[2]==n) ans=="Yes";
	cout<<ans;	
		
	return 0;
}