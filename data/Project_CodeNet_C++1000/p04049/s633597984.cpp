#include<bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f;
const int N=2010;
int n,k;
int fr,to;
vector<int>ed[N];
int dist[N][N];
int ans=INF;

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		scanf("%d%d",&fr,&to);
		ed[--fr].push_back(--to);
		ed[to].push_back(fr);
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			dist[i][j]=INF;
	for(int i=0;i<n;i++)
		dist[i][i]=0;
//	puts("Input has finished!");
//	puts("Step 1...");
	for(int x=0;x<n;x++){
		queue<int>q;
		q.push(x);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=0;i<ed[u].size();i++){
				int v=ed[u][i];
				if(dist[x][v]<INF) continue;
				dist[x][v]=dist[x][u]+1;
				q.push(v);
			}
		}
//		printf("	Point %d",x);
//		puts(" has finished!");
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++) printf("%d ",dist[i][j]);
//		puts("");
//	}
//	puts("Step 1 has finished!");
//	puts("Step 2...");
	if(k%2==1){
		for(int u=0;u<n;u++){
			for(int kk=0;kk<ed[u].size();kk++){
				int v=ed[u][kk];
				int cnt=0;
				for(int i=0;i<n;i++)
					if(dist[u][i]+dist[v][i]<=k) cnt++;
				ans=min(ans,n-cnt);
			}
		}
	} else {
		for(int i=0;i<n;i++){
			int cnt=0;
			for(int j=0;j<n;j++)
				if(dist[i][j]<=k/2) cnt++;
			ans=min(ans,n-cnt);
		}
	}
//	puts("Step 2 has finished!");
	printf("%d\n",ans);
	return 0;
}