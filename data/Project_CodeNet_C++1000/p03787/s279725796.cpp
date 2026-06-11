#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define ll long long

using namespace std;

const int N=1e5+10,M=2e5+10;
int n,m,cnt,head[N],x,y,tot,flag,col[N]; ll a,b,c;
struct edge{int to,nxt;}e[M<<1];

void adde(int x,int y){
	e[++cnt].to=y; e[cnt].nxt=head[x]; head[x]=cnt;
}

void dfs(int u,int c){
	++tot,col[u]=c;
	for (int i=head[u],v;i;i=e[i].nxt){
		v=e[i].to;
		if (col[v]==-1) dfs(v,c^1);
		else if (col[v]==c) flag=1;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	rep (i,1,m) scanf("%d%d",&x,&y),adde(x,y),adde(y,x);
	memset(col,-1,sizeof(col));
	rep (i,1,n) if (col[i]==-1){
		tot=0,flag=0,dfs(i,0);
		if (tot==1) a++;
		else if (flag) b++;
		else c++;
	}
	printf("%lld\n",a*(2*n-1)-a*(a-1)+c*c*2+b*b+b*c*2);
	return 0;
}