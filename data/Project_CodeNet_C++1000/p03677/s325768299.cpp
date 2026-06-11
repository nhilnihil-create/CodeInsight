#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define of(i,l,r) for(int i=l;i>=r;i--)
#define fe(i,u) for(int i=head[u];i;i=e[i].next)
using namespace std;
typedef long long ll;
inline void open(const char *s)
{
	#ifndef ONLINE_JUDGE
	char str[20];
	sprintf(str,"in%s.txt",s);
	freopen(str,"r",stdin);
//	sprintf(str,"out%s.txt",s);
//	freopen(str,"w",stdout);
	#endif
}
inline int rd()
{
	static int x,f;
	x=0;f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return f>0?x:-x;
}
const int N=100010;
const ll Inf=1000000000000000000ll;
int n,m,a[N],rt;
ll ans=0,mx,delta;

namespace Seg{
#define lson tr[o].ls,l,mid
#define rson tr[o].rs,mid+1,r
#define qlson lson,L,min(mid,R)
#define qrson rson,max(mid+1,L),R
struct tree{
	int ls,rs;ll tag,siz;
	tree(){ls=rs=tag=siz=0;}
}tr[N<<1];int cnt=0;

void build(int &o,int l,int r)
{
	o=++cnt;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(lson);build(rson);
}

inline void pushdown(int o,int l,int mid,int r,int ty)
{
	if(tr[o].tag==0)return;
	int ls=tr[o].ls,rs=tr[o].rs;
	tr[ls].tag+=tr[o].tag;tr[ls].siz+=tr[o].siz;
	tr[rs].tag+=tr[o].tag+tr[o].siz*(mid-l+1ll);tr[rs].siz+=tr[o].siz;
//	if(!ty)printf("pushdown of %d %d %d %d:\n",l,mid,mid+1,r);
//	if(!ty)printf("%lld %lld\n\n",tr[o].tag,tr[o].tag+tr[o].siz*(mid-l+1));
	tr[o].tag=tr[o].siz=0;
}

void modify(int o,int l,int r,int L,int R,ll &x)
{
	if(L>R)return;
	if(l==L&&r==R){
		tr[o].tag+=x;tr[o].siz++;
//		printf("add: %d %d %lld\n",L,R,x);
		x+=r-l+1;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(o,l,mid,r,0);
	if(L<=mid)modify(qlson,x);
	if(R>mid)modify(qrson,x);
}

void travel(int o,int l,int r)
{
	if(l==r){
//		printf("%lld ",tr[o].tag);
		return void(mx=max(mx,tr[o].tag));
	}
	int mid=(l+r)>>1;
	pushdown(o,l,mid,r,1);
	travel(lson);travel(rson);	
}

}

int main()
{
	n=rd();m=rd();
	fo(i,1,n)a[i]=rd();
	Seg::build(rt,1,m);
	fo(i,2,n){
		ans+=(a[i]>a[i-1])?a[i]-a[i-1]:a[i]+m-a[i-1];
		if(a[i]>a[i-1])Seg::modify(rt,1,m,a[i-1]+2,a[i],delta=1);
		else{
			Seg::modify(rt,1,m,a[i-1]+2,m,delta=1);
			if(a[i-1]<m)Seg::modify(rt,1,m,1,a[i],delta=m-a[i-1]);
			else Seg::modify(rt,1,m,2,a[i],delta=1);
		}
	}
	mx=-Inf;Seg::travel(rt,1,m);
//	puts("");
	ans-=mx;
	printf("%lld\n",ans);
	return 0;
}
