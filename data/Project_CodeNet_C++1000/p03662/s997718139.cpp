#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> graph[100002];
int dis[2][100002];
void dfs(int d,int v,int p){
	for(int i=0;i<graph[v].size();i++){
		int y=graph[v][i];
		if(y!=p){
			dis[d][y]=dis[d][v]+1;
			dfs(d,y,v);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dis[0][1]=0;
	dfs(0,1,0);
	dis[1][n]=0;
	dfs(1,n,0);
	int cnt[2]={0};
	for(int i=1;i<=n;i++){
		cnt[dis[0][i]>dis[1][i]]++;
	}
	string ans[2]={"Fennec","Snuke"};
	cout<<ans[cnt[0]<=cnt[1]]<<endl;
	return 0;
}