#include<bits/stdc++.h>
using namespace std;
queue<int> q;
vector<int> ga[2001];
int dist[2001][2001];
pair<int,int> e[2001];
int n,k;
void BFS(int id){
	q.push(id);
	dist[id][id]=0;
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		for(int i=0;i<ga[cur].size();i++)
		{
			int nxt=ga[cur][i];
			if(dist[id][nxt]>1e9){
				dist[id][nxt]=dist[id][cur]+1;
				q.push(nxt);
			}
		}
	}
} 
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		ga[a].push_back(b);
		ga[b].push_back(a);
		e[i]=make_pair(a,b);
	}
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=n;i++)
		BFS(i);
	int res=1e9;
	if(k%2==0){
		for(int i=1;i<=n;i++){
			int ans=0;
			for(int j=1;j<=n;j++){
				if(dist[i][j]>k/2)
					ans++;
			}
			res=min(res,ans);
		}
	}
	if(k%2==1){
		for(int i=1;i<n;i++){
			int ans=0;
			for(int j=1;j<=n;j++){
				if(dist[e[i].first][j]>k/2&&dist[e[i].second][j]>k/2)
					ans++;
			}
			res=min(res,ans);
		}
	}
	cout<<res<<endl;
	return 0;
}
