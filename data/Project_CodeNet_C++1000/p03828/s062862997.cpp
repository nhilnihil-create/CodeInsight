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
	int n; cin>>n;
	set<int> pri;
	map<int,int> mp;
	rep(i,2,n+1){
		bool ok=true;
		rep(j,2,sqrt(i)+1){
			if(i%j==0 && i!=j) ok=false;
		}
		if(ok) pri.insert(i);
	}
	rep(i,2,n+1){
		int k=i;
		while(k>1){
			for(int c:pri){
				if(k==1) break;
				if(k%c==0){
					mp[c]++;
					k/=c;
				}
			}
		}
	}
	ll ans=1;
	for(auto c:mp){
		ans*=c.second+1;
		ans%=MOD;
	}
	cout<<ans;
	return 0;
}