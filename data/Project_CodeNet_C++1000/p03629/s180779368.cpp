#include<bits/stdc++.h>
#define N 500005
#define pi pair<char,int>
#define mk make_pair
using namespace std;
vector<pi>G[N];
char s[N],s1[N],pre1[N];
int n,kk,left1,right1,pre[N],nxt[N],dis[N],q[N],head[N],nx[N][27];
inline void link(int x,int y,char z){G[x].push_back(mk(z,y));}
inline void bfs(){
	q[left1=1]=0;right1=1;
	dis[0]=0;memset(dis,0,sizeof(dis));
	while (left1<=right1){
		int u=q[left1++];
		for (int i=0;i<(int)G[u].size();i++){
			int v=G[u][i].second;
			if (dis[v]) continue;
			dis[v]=dis[u]+1;
			q[++right1]=v;
			pre[v]=u;pre1[v]=G[u][i].first;
		}
	}
}
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	for (int i=1;i<=26;i++) nxt[i]=n+1;
	for (int i=n;~i;i--){
		for (int j=1;j<=26;j++) nx[i][j]=nxt[j];
		if(!i)break;nxt[s[i]-'a'+1]=i;
	}
	for (int i=0;i<=n;i++)
		for (int j=1;j<=26;j++) link(i,nx[i][j],'a'+j-1);
	for (int i=0;i<=n;i++) sort(G[i].begin(),G[i].end());
	bfs();
	int cnt=dis[n+1];
	for (int i=n+1;i;i=pre[i]) s1[cnt--]=pre1[i];
	for (int i=1;i<=dis[n+1];i++) printf("%c",s1[i]);
	return 0;
}