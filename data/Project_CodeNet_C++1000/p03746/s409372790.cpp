#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,a,b,vis[N],x,y;
vector<int>v[N],path,path2;
void dfs(int x){
	vis[x]=1;
	path.push_back(x);
	for (int i:v[x])
		if (!vis[i]){
			dfs(i);
			return;
		}
}
int main(){
	scanf("%d%d",&n,&m);
	while (m--){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	swap(path,path2);
	dfs(1);
	printf("%d\n",path2.size()+path.size()-1);
	for (int i=path2.size()-1;i>0;i--)printf("%d ",path2[i]);
	for (int i:path)printf("%d ",i);
}
