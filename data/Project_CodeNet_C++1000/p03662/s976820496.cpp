#include<bits/stdc++.h>
#define INF 2147483647
#define LLINF 9223372036854775807
typedef long long ll;
using namespace std;
int n;
vector<int> v[100010];
vector<int> Root;
bool vis[100010];
int none;
int cnt=0;
bool dfs(int x){
	vis[x]=1;
	if(x==n)return 1;
	for(int i=0;i<v[x].size();i++){
		if(!vis[v[x][i]]){
			Root.push_back(v[x][i]);
			if(dfs(v[x][i]))return 1;
			Root.erase(Root.begin()+Root.size()-1);
		}
	}
	return 0;
}
void dfs2(int x){
	vis[x]=1;
	cnt++;
	for(int i=0;i<v[x].size();i++){
		if(!vis[v[x][i]]&&v[x][i]!=none){
			dfs2(v[x][i]);
		}
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	Root.push_back(1);
	dfs(1);
	none=Root[(Root.size()+1)/2];
	memset(vis,0,sizeof(vis));
	dfs2(1);
	if(cnt*2>n)cout<<"Fennec"<<endl;
	else cout<<"Snuke"<<endl;
	return 0;
}