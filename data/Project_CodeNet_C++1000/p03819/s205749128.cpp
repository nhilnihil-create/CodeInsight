#include<cstdio>
#include<algorithm>
using namespace std;

const int N=300005,M=100005;
int n,m,cnt[M*4];
struct node
{
	int l,r;
}a[N];
bool operator<(const node&a,const node&b){return a.r-a.l<b.r-b.l;}

void insert(int u,int l,int r,int ql,int qr)
{
	if(l>=ql&&r<=qr){cnt[u]++;return;}
	int mid=l+r>>1;
	if(ql<=mid)insert(u<<1,l,mid,ql,qr);
	if(qr>mid)insert(u<<1|1,mid+1,r,ql,qr);
}

int query(int p)
{
	int ans=0,u=1,l=1,r=m;
	for(;;)
	{
		ans+=cnt[u];
		if(l==r)break;
		int mid=l+r>>1;
		if(p<=mid)u=u<<1,r=mid;
		else u=u<<1|1,l=mid+1;
	}
	return ans;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+1+n);
	for(int i=1,j=1;i<=m;i++)
	{
		while(j<=n&&a[j].r-a[j].l<i)insert(1,1,m,a[j].l,a[j].r),j++;
		int ans=0;
		for(int k=i;k<=m;k+=i)ans+=query(k);
		printf("%d\n",ans+n-j+1);
	}
	return 0;
}
