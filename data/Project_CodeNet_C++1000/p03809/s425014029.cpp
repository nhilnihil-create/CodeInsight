#include <algorithm>
#include <cstdio>

const int N=100005;
int fst[N],deg[N],a[N],tot=0;

struct Edge{
	int to,nxt;
}e[N*2];

void addedge(int x,int y){
	e[++tot].to=y;e[tot].nxt=fst[x];fst[x]=tot;deg[y]++;
}

bool dfs(int x,int father){
	if (deg[x]==1){
		
		return 1;
	}
	int sum=0,mx=0;
	for (int i=fst[x];i;i=e[i].nxt){
		int y=e[i].to;
		if (y!=father){
			if (!dfs(y,x)) return 0;
			sum+=a[y];
			mx=std::max(mx,a[y]);
		}
	}
	a[x]=a[x]*2-sum;
	return (a[x]>=0 && mx*2-sum<=a[x] && a[x]<=sum);
}

int main(){
	int n,root=0;
	scanf("%d\n",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	if (n==2){
		printf(a[1]==a[2]?"YES":"NO");
		return 0;
	}
	for (int i=1;i<=n;i++)
		if (deg[i]>1) root=i;
	if (dfs(root,0) && !a[root]) printf("YES\n");
		else printf("NO\n");
}