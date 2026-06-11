#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> graph[100002];
int mc[100002]={0};
int cnt=0,ml,cut;
vector<int> main_road;
void dfs_m(int v,int p){
	for(int i=0;i<graph[v].size();i++){
		int y=graph[v][i];
		if(y!=p) dfs_m(y,v);
	}
	if(v==ml){
		main_road.push_back(v);
		ml=p;
	}
}
void dfs_e(int v,int p){
	if(mc[v]>cut) return;
	for(int i=0;i<graph[v].size();i++){
		int y=graph[v][i];
		if(y!=p) dfs_e(y,v);
	}
	cnt++;
}
int main(){
	scanf("%d",&n);
	ml=n;
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs_m(1,0);
	reverse(main_road.begin(),main_road.end());
	for(int i=0;i<main_road.size();i++){
		mc[main_road[i]]=i+1;
	}
	cut=(main_road.size()+1)/2;
	dfs_e(1,0);
	cout<<((cnt*2>n)?"Fennec":"Snuke")<<endl;
	return 0;
}