#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=3e5+5;
int n,m;
int ans[MAXN];
namespace Seg
{
	#define ls (x<<1)
	#define rs (x<<1|1)
	int add[MAXN<<2],sum[MAXN<<2];
	void down(int x,int l,int r)
	{
		if(!add[x]) return;
		int mid=l+r>>1;
		add[ls]+=add[x];
		add[rs]+=add[x];
		sum[ls]+=add[x]*(mid-l+1);
		sum[rs]+=add[x]*(r-mid);
		add[x]=0;
	}
	void up(int x)
	{
		sum[x]=sum[ls]+sum[rs];
	}
	void fix(int x,int l,int r,int ql,int qr)
	{
		if(ql<=l&&r<=qr)
		{
			add[x]++;
			sum[x]+=(r-l+1);
			return;
		}
		int mid=l+r>>1;
		down(x,l,r);
		if(ql<=mid) fix(ls,l,mid,ql,qr);
		if(qr>mid) fix(rs,mid+1,r,ql,qr);
		up(x);
	}
	int query(int x,int l,int r,int pos)
	{
		if(l==r) return sum[x];
		down(x,l,r);
		int mid=l+r>>1;
		if(pos<=mid) return query(ls,l,mid,pos);
		else return query(rs,mid+1,r,pos);
	}
}
pair<int,int>p[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,l,r;i<=n;i++)
		scanf("%d%d",&l,&r),p[i]=make_pair(r-l+1,l);
	sort(p+1,p+n+1);
	int cnt=1;
	for(int i=1;i<=m;i++)
	{
		while(cnt<=n&&p[cnt].first<i)
		{
			Seg::fix(1,1,m,p[cnt].second,p[cnt].first+p[cnt].second-1);
			cnt++;
		}
		int ans=n-cnt+1;
		for(int j=i;j<=m;j+=i)
			ans+=Seg::query(1,1,m,j);
		printf("%d\n",ans);
	}
	return 0;
}