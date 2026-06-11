#include<bits/stdc++.h>
using namespace std;
int n,k;
struct Star{
	int s,e,to;
}edge[4010];
int head[2010];
int d[2010];
int cnt=0,sum=0;
void dfs(int x,int fa){
	for(int i=head[x];~i;i=edge[i].to){
		int nxt=edge[i].e;
		if(nxt==fa) continue;
		d[nxt]=d[x]+1;
//		printf("%d\n",d[nxt]);
		if(d[nxt]>k/2) sum++;
		dfs(nxt,x);
	}
}
int main(){
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		edge[++cnt].s=x,edge[cnt].e=y,edge[cnt].to=head[x];head[x]=cnt;
		edge[++cnt].s=y,edge[cnt].e=x,edge[cnt].to=head[y];head[y]=cnt;
	}
	int ans=0x7fffffff;
	if(k&1){
		for(int i=1;i<=2*n-2;i++){
			sum=0;
			int x=edge[i].s,y=edge[i].e;
			d[x]=d[y]=0;dfs(x,y);dfs(y,x);
			ans=min(ans,sum);
		}
	}
	else{
		for(int i=1;i<=n;i++){
			sum=0;
			d[i]=0;
			dfs(i,0);
			ans=min(ans,sum);
		}
	}
	printf("%d",ans);
	return 0;
}