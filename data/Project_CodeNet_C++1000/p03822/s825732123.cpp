#include <bits/stdc++.h>
#define int long long
#define mod (int)(1e9+7)
#define inf (int)(3e18+7)
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P pair<int,int>
#define all(v) v.begin(),v.end()
#define mkp make_pair
#define mkt make_tuple
#define prique(T) priority_queue<T,vector<T>,greater<T>>
#define vecunique(vec) sort(vec.begin(), vec.end());decltype(vec)::iterator result = std::unique(vec.begin(), vec.end());vec.erase(result, vec.end())
using namespace std;

/*--------Library Zone!--------*/

int n,a[114514];
vector<int>G[114514];
int dfs(int x){
	vector<int>v;
	for(int i:G[x]){
		v.push_back(dfs(i));
	}
	int ans=0;
	sort(all(v),greater<>());
	rep(i,v.size()){
		ans=max(ans,v[i]+i+1);
	}
	//cout<<x<<" "<<ans<<endl;
	return ans;
}
signed main(){
	cin>>n;
	REP(i,n){
		cin>>a[i];a[i]--;
		G[a[i]].push_back(i);
	}
	cout<<dfs(0)<<endl;
}
