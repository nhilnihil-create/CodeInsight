#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct trnode{
	int lc,rc,c;
}tr[25000010];int tot=0,root[300010];
int n,m;
struct node{
	int l,r;
}a[300010];
bool cmp(node a,node b) {return a.l<b.l;}
void update(int &x,int l,int r,int k,int c)
{
	tr[++tot]=tr[x];x=tot;
	if(l==r) {tr[x].c+=c;return;}
	int mid=(l+r)/2;
	if(k<=mid) update(tr[x].lc,l,mid,k,c);
	else update(tr[x].rc,mid+1,r,k,c);
	tr[x].c=tr[tr[x].lc].c+tr[tr[x].rc].c;
}
int findans(int x,int l,int r,int fl,int fr)
{
	if(!x) return 0;
	if(l==fl&&r==fr) return tr[x].c;
	int mid=(l+r)/2;
	if(fr<=mid) return findans(tr[x].lc,l,mid,fl,fr);
	else if(fl>mid) return findans(tr[x].rc,mid+1,r,fl,fr);
	return findans(tr[x].lc,l,mid,fl,mid)+findans(tr[x].rc,mid+1,r,mid+1,fr);
}
void add(int &x,int l,int r,int c)
{
	update(x,1,n,l,c);
	if(r!=n) update(x,1,n,r+1,-c);
}
int main()
{
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++) scanf("%d %d",&a[i].l,&a[i].r);
	sort(a+1,a+m+1,cmp);
	int p=0;
	for(int i=1;i<=m;i++) add(root[0],a[i].l,a[i].r,1);
	for(int i=1;i<=n;i++)
	{
		root[i]=root[i-1];
		while(p<m&&a[p+1].l==i) p++,add(root[i],a[p].l,a[p].r,-1);
	}
	//printf("ok\n");
	for(int i=1;i<=n;i++)
	{
		int ans=0;
		//printf("solve:%d\n",i);
		for(int j=i;j<=n;j+=i) ans+=findans(root[j-i],1,n,1,j);//printf("%d->%d %d\n",j-i,j,ans);
		printf("%d\n",ans);
	}
}