#include<bits/stdc++.h>
using namespace std;
const int inf=1<<30;
int cnt[100010],middle=0;
vector<int> g[100010];
vector<int> nums;
int n;
void dfs(int now,int par){
	//cout<<now<<" "<<par<<endl;
	cnt[now]=1;
	nums.push_back(now);
	if(now==n){
		middle=nums[(nums.size()+1)/2];
	}
	for(int i=0;i<g[now].size();i++){
		if(g[now][i]==par)continue;
		dfs(g[now][i],now);
		cnt[now]+=cnt[g[now][i]];
	}
	nums.pop_back();
	return;
}
int main(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a); 
	}
	dfs(1,0);
	//cout<<cnt[middle]<<endl;
	string ans=(cnt[middle]*2<n)?"Fennec":"Snuke";
	cout<<ans<<endl;
	return 0;
}