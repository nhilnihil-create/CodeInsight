#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int fir[100010],dis[200010],nxt[200010],id;
int qd[100010],qx[100010],qc[100010],ans[100010];
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int f[100010][11];
void dfs(int x,int y,int c){
	f[x][y]=c;for(int i=y-1;~i&&!f[x][i];--i)f[x][i]=c;if(!y)return;
	for(int i=fir[x];i;i=nxt[i])if(!f[dis[i]][y-1])dfs(dis[i],y-1,c);
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),a,b;
	for(int i=1;i<=m;++i)a=gi(),b=gi(),link(a,b),link(b,a);
	int q=gi();
	for(int i=1;i<=q;++i)qx[i]=gi(),qd[i]=gi(),qc[i]=gi();
	for(int i=q;i;--i)if(!f[qx[i]][qd[i]])dfs(qx[i],qd[i],qc[i]);
	for(int i=1;i<=n;++i){
		int res=0;
		for(int j=0;j<=10;++j)if(f[i][j]){res=f[i][j];break;}
		printf("%d\n",res);
	}
	return 0;
}
