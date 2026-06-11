#include<bits/stdc++.h>
#define ll long long
#define rint register int
using namespace std;
const int N=1e5+7;
int tot,n,m,q,v[N],d[N],c[N],first[N];
int f[N][11];
struct fuk
{
	int x,next;
}a[N<<2];
inline void add(int x,int to)
{
	tot++;
	a[tot].next=first[x]; a[tot].x=to; first[x]=tot;
}
void dfs(int x,int d,int col)
{
	if(d==-1) return;
	if(f[x][d]) return;
	f[x][d]=col; 
	for(int i=first[x];i;i=a[i].next)
	{
		int y=a[i].x;
		dfs(y,d-1,col);
	}
}
int main()
{
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++)
  {
  	int x,y; scanf("%d%d",&x,&y);
  	add(x,y); add(y,x);
  } 
  for(int i=1;i<=n;i++) add(i,i);
  scanf("%d",&q);
  for(int i=1;i<=q;i++) scanf("%d%d%d",&v[i],&d[i],&c[i]);
  for(int i=q;i>=1;i--)
	dfs(v[i],d[i],c[i]); 
  for(int i=1;i<=n;i++)
    printf("%d\n",f[i][0]);
  return 0;
}
