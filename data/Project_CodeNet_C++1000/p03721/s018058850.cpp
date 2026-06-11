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
#define print(a) cout<<(a)<<endl;
#define to_ll(b) stoll(b)
#define MOD 1000000007

int main(){
	ll N,K; cin>>N>>K;
	vi vec(0);
	map<ll,ll> mp;
	rep(i,0,N){
		ll a,b; cin>>a>>b;
		mp[a]+=b;
	}
	ll ans=0;
	for(auto p:mp){
		K-=p.second;
		if(K<=0){
			ans=p.first;
			break;
		}
	}
	//sort(all(vec));
	cout<<ans;
	
	
}