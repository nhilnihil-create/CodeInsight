#include <bits/stdc++.h>
#define LL long long
#define mp make_pair
#define pb push_back
#define INF (1<<29)
using namespace std;
typedef pair<int,int>pii;
int n;
vector<int>G[100010];
int df[100010],ds[100010];
void bfs(int fx,int dist[100010]){
	queue<int>qq;
	qq.push(fx);
	for(int i=1;i<=n;i++)dist[i]=-1;
	dist[fx]=0;
	while(!qq.empty()){
		int node=qq.front();
		qq.pop();
		for(auto i:G[node]){
			if(dist[i]!=-1)continue;
			dist[i]=dist[node]+1;
			qq.push(i);
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		G[x].pb(y);
		G[y].pb(x);
	}
	bfs(1,df);
	bfs(n,ds);
	int f=0,s=0;
	for(int i=1;i<=n;i++){
		if(df[i]<=ds[i])f++;
		else s++;
	}
	if(f>s)cout<<"Fennec\n";
	else cout<<"Snuke\n";
//	cout<<f<<' '<<s<<endl;
//	for(int i=1;i<=n;i++)cout<<df[i]<<' ';
//	puts("");
//	for(int i=1;i<=n;i++)cout<<ds[i]<<' ';
//	puts("");
	return 0;
}
