#include <bits/stdc++.h>
#define LL long long
#define int LL
#define P pair<int, int>
#define Fengexian cout<<"WZY%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl
const LL N = 2e5 + 10;
const LL mod = 998244353;
const LL inf = 0x3f3f3f3f;
const double eps = 1e-9;
using namespace std;
template <typename tp>
inline void read(tp &x)
{
	x = 0; char c = getchar(); bool f = 0;
	for (; c < '0' || c > '9'; f |= (c == '-'), c = getchar()) ;
	for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar()) ;
	if (f) x = -x;
}
LL ans;
int n,a[N];
int tree[N<<2];
void change(int now,int l,int r,int q,int k)
{
	if(l==r) { tree[now] = k; return;}
	int mid=(l+r)>>1;
	if(q<=mid) change(now<<1,l,mid,q,k);
	else change(now<<1|1,mid+1,r,q,k);
	tree[now]=max(tree[now<<1],tree[now<<1|1]);
} 
int query(int now,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr) return tree[now];
	if(ql>r||qr<l) return 0;
	int mid=(l+r)>>1;
	return max(query(now<<1,l,mid,ql,qr),query(now<<1|1,mid+1,r,ql,qr));
}
void clear(int now,int l,int r)
{
	tree[now]=n+1;
	if(l==r) return ;
	int mid=(l+r)>>1;
	clear(now<<1,l,mid);
	clear(now<<1|1,mid+1,r);
}
void change2(int now,int l,int r,int q,int k)
{
	if(l==r) { tree[now] = k; return;}
	int mid=(l+r)>>1;
	if(q<=mid) change2(now<<1,l,mid,q,k);
	else change2(now<<1|1,mid+1,r,q,k);
	tree[now]=min(tree[now<<1],tree[now<<1|1]);
} 
int query2(int now,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr) return tree[now];
	if(ql>r||qr<l) return n+1;
	int mid=(l+r)>>1;
	return min(query2(now<<1,l,mid,ql,qr),query2(now<<1|1,mid+1,r,ql,qr));
}
int l[N],r[N];
signed main()
{
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++)
	{
		l[i]=query(1,1,n,1,a[i]);
		change(1,1,n,a[i],i);
	}
	clear(1,1,n);
	for(int i=n;i>=1;i--)
	{
		r[i]=query2(1,1,n,1,a[i]);
		change2(1,1,n,a[i],i);
	}
	for(int i=1;i<=n;i++)
		ans+=a[i]*(i-l[i])*(r[i]-i);
	printf("%lld\n",ans);
	return 0;
}
