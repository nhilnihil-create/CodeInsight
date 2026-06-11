#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
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
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	int ans=1;
	int n; cin>>n;
	map<int,int> mp;
	rep(i,0,n){
		int a; cin>>a;
		mp[a]++;
		if(mp[a]==3){
			cout<<0;
			return 0;
		}
	}
	if(mp[0]>1){
		cout<<0;
		return 0;
	}
	rep(i,0,n/2){
		ans*=2;
		ans=ans%MOD;
	}
	cout<<ans;
	return 0;
}