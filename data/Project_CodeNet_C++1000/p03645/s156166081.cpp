#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>graph[200005];
bool visited[200005];
bool f(int curr,int dist){
	visited[curr] = true;
	if(dist==2) return (curr==n);
	bool ret = 0;
	for(int i=0; i<graph[curr].size(); i++){
		int nx = graph[curr][i];
		if(!visited[nx]) ret|=f(nx,dist+1);
	}
	return ret;
}
int main(){
	int m;
	cin>>n>>m;
	while(m--){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	if(f(1,0)) cout<<"POSSIBLE";
	else cout<<"IMPOSSIBLE";
}