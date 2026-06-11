#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> graph[100002];
int cnt[100002],fis=-1;
vector<int> ds;
void dfs(int v,int p){
	cnt[v]=1;
	ds.push_back(v);
	if(v==n){
		fis=ds[(ds.size()+1)/2];
	}
	for(int i=0;i<graph[v].size();i++){
		int u=graph[v][i];
		if(u!=p){
			dfs(u,v);
			cnt[v]+=cnt[u];
		}
	}
	ds.pop_back();
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(1,0);
	cout<<((cnt[fis]*2<n)?"Fennec":"Snuke")<<endl;
	return 0;
}
