#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,m,cnt,tot,fst[N],pnt[N<<1],nxt[N<<1],ans[N],dp[N][11];
void add(int x,int y){
	pnt[++tot]=y; nxt[tot]=fst[x]; fst[x]=tot;
}
int main(){
	scanf("%d%d",&n,&m);
	int i,j,x,y;
	for (i=1; i<=m; i++){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	scanf("%d",&cnt);
	for (i=1; i<=cnt; i++){
		scanf("%d%d%d",&x,&y,&ans[i]); dp[x][y]=i;
	}
	for (i=9; i>=0; i--)
		for (x=1; x<=n; x++){
			dp[x][i]=max(dp[x][i],dp[x][i+1]);
			for (j=fst[x]; j; j=nxt[j]) dp[x][i]=max(dp[x][i],dp[pnt[j]][i+1]);
		}
	for (i=1; i<=n; i++) printf("%d\n",ans[dp[i][0]]);
	return 0;
}