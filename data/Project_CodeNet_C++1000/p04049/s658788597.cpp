#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
vector<int> v[N];
int sum;
void dfs(int u,int fa,int s){
	sum++;
	if(!s) return ;
	for(int i=0;i<v[u].size();i++){
		if(v[u][i]==fa) continue;
		dfs(v[u][i],u,s-1);
	}
}
signed main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int ans=0;
	if(k%2==0){
		for(int i=1;i<=n;i++){
			sum=0;
			dfs(i,-1,k/2);
			ans=max(ans,sum);
		}
	}else{
		for(int i=1;i<=n;i++){
			for(int j=0;j<v[i].size();j++){
				sum=0;
				dfs(i,v[i][j],k/2);
				dfs(v[i][j],i,k/2);
				ans=max(ans,sum);
			}
		}
	}
	cout<<n-ans;
	return 0;
}