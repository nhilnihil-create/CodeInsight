#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,head[100005],cc,A,ans,mx[100005],dep[100005];
struct sd{int next,to;}seg[200005];
inline void addseg(int v,int r) {seg[++cc].next=head[v];head[v]=cc;seg[cc].to=r;}
inline void dfs(int v,int fa) {
	dep[v]=dep[fa]+1;mx[v]=dep[v];
	for(int i=head[v];i;i=seg[i].next) if(seg[i].to!=fa) dfs(seg[i].to,v);
	for(int i=head[v];i;i=seg[i].next) if(seg[i].to!=fa) mx[v]=max(mx[v],mx[seg[i].to]);
	if(mx[v]-dep[v]+1==m&&v!=1&&dep[v]!=2) {++ans;mx[v]=dep[v]-1;}
}
int main()
{
	scanf("%d%d",&n,&m);scanf("%d",&A);if(A!=1) ++ans;
	for(int i=2;i<=n;++i) {scanf("%d",&A);addseg(A,i);addseg(i,A);}
	dfs(1,0);
	printf("%d",ans);
	return 0;
}