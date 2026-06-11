#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

ll dfs(bitset<15> b,int k,vector<int> &a,int now){
	ll ans=1e18;
	int n=a.size();
	if(now==n){
		if(b.count()!=k) return ans;
		ll sum{};
		int hi{a.at(0)};
		for(int i=1; i<n; i++){
			if(b.test(i)){
				if(a.at(i)<=hi) {
					sum+=hi-a.at(i)+1;
					hi++;
				}
			}
			hi = max(hi,a.at(i));
		}
		ans = sum;
	}
	else {
		ans=min(ans,dfs(b,k,a,now+1));
		b.set(now);
		ans=min(ans,dfs(b,k,a,now+1));
		b.reset(now);
	}
	return ans;
}
 
int main(){
	
	int n,k; cin>>n>>k;
	vector<int> a(n);
	for(auto &i:a) cin>>i;
	cout <<dfs(bitset<15>(),k,a,0)<<endl;
	
	
}