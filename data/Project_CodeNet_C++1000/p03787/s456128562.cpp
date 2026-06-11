#include <cstdio>

const int N=100005;

int fst[N],f[N],tot=0;

struct Edge{
	int to,nxt;
}e[N*4];

void addedge(int x,int y){
	e[++tot].to=y;e[tot].nxt=fst[x];fst[x]=tot;
}

bool dfs(int x,int v){
	f[x]=v;v^=1;
	bool flag=1;
	for (int i=fst[x];i;i=e[i].nxt){
		int y=e[i].to;
		if (f[y]==-1) flag&=dfs(y,v);
			else if (f[y]!=v) flag=0;
	}
	return flag;
}

int main(){
	int n,m;
	scanf("%d%d\n",&n,&m);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d\n",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	for (int i=1;i<=n;i++) f[i]=-1;
	long long a=0,b=0,c=0;
	for (int i=1;i<=n;i++)
	if (f[i]==-1){
		if (dfs(i,0)){
			if (!fst[i]) a++;else b++;
		}
		else c++;
	}
	printf("%lld\n",2*a*n-a*a+2*b*b+2*b*c+c*c);
}