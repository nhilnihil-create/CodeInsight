#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+7;
int n,m,cnt,hd[N],v[N*2],nxt[N*2];
void add(int x,int y){v[++cnt]=y,nxt[cnt]=hd[x],hd[x]=cnt;}
int dfs(int x,int fa)
{
	int l=0;
	for(int i=hd[x];i;i=nxt[i])
	if(v[i]!=fa)l^=dfs(v[i],x)+1;
	return l;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
	if(dfs(1,0))puts("Alice");else puts("Bob");
}