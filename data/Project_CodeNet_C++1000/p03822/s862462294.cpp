#include <cstdio>
#include <algorithm>
#define rep(i,j,k) for (i=j;i<=k;i++)
using namespace std;
const int N=1e5+5;
int n,i,l,r,x,y,f,bn,son[N],fs[N],bro[N],fa[N],q[N],b[N],g[N];
void add(int x,int y) {
	bro[y]=fs[x]; fs[x]=y;
}
int main()
{
//	freopen("tournament.in","r",stdin);
//	freopen("tournament.out","w",stdout);
	scanf("%d",&n);
	rep(i,2,n) scanf("%d",&fa[i]),son[fa[i]]++,add(fa[i],i);
	rep(i,1,n) if (!son[i]) q[++r]=i;
	for (l=1;l<=r;l++)
	{
		x=q[l];
		if (fs[x]) {
			for (y=fs[x],bn=0;y;y=bro[y]) b[++bn]=g[y];
			sort(b+1,b+1+bn);
			rep(i,1,bn) g[x]=max(g[x],b[i])+1;
		}
		if (x==1) break;
		f=fa[x]; son[f]--; if (!son[f]) q[++r]=f;
	}
	printf("%d\n",g[1]);	
	return 0;
}