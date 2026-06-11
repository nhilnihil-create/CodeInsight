#include <cstdio>
#include <algorithm>
#define rep(i,j,k) for (i=j;i<=k;i++)
using namespace std;
const int N=1e5+5;
int n,i,u,v,flag;
int En,fst[N],a[N],b[N],up[N],nxt[N*2],to[N*2];
void add(int u,int v) {
	En++; nxt[En]=fst[u]; fst[u]=En; to[En]=v;
}
void dfs(int x,int fa)
{
	int i,j,cnt=0,son=0,rest,sum=0,SUM,t1,t2;
	for (j=fst[x];j;j=nxt[j])
		if (to[j]!=fa) {
			son++;
			dfs(to[j],x);
			if (!flag) return ;
		}
	if (!son) {up[x]=a[x]; return ;}
	for (j=fst[x];j;j=nxt[j])
		if (to[j]!=fa) if (up[to[j]]) b[++cnt]=up[to[j]];
	sort(b+1,b+1+cnt);
	rep(i,1,cnt-1) sum+=b[i];
	SUM=sum+b[cnt];
	if (!cnt) rest=0;
	else if (sum<=b[cnt]) rest=b[cnt]-sum;
	else rest=SUM%2;
	t1=2*(SUM-a[x]); t2=SUM-t1;
	if (t1<0 || t2%2 != rest%2 || t2<rest) { flag=0; return ; }
	up[x]=t2; if (x==1 && son==1) up[x]=0;
}
int main()
{
	//freopen("clean.in","r",stdin);
	//freopen("clean.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n-1)
	{
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	flag=1;
	dfs(1,1);
	if (up[1]) flag=0;
	if (flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}