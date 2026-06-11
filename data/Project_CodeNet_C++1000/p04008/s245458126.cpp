#include<bits/stdc++.h>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long int ll;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
const ll INF=1000000010;
const ll LINF=4000000000000000010LL;
const int MAX=310;
const double EPS=1e-3;
int a[100010];
vector<int> G[100010];
int n,k,ans;
int dfs(int i){
	int dep=0;
	for(auto &e:G[i]){
		dep=max(dep,dfs(e));
	}
	dep++;
	if(dep>=k){
		ans++;
		return 0;
	}else{
		return dep;
	}
}
int main(){
	ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];a[i]--;if(i!=0)G[a[i]].push_back(i);
	}
	if(a[0]!=0)ans++;
	for(int i=1;i<n;i++){
		if(a[i]==0){
			for(auto &e:G[i])dfs(e);
		}
	}
	cout<<ans<<endl;
    return 0;
}
