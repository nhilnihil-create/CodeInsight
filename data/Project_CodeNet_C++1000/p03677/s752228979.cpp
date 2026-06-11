#include <bits/stdc++.h>
#define N 200010
#define int long long
using namespace std;

inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int tree[N<<2],Add[N<<2];
inline void deal(int x,int y)
{
	Add[x]+=y; tree[x]+=y;
}
inline void pushdown(int rt)
{
	if(Add[rt])
	{
		deal(rt<<1,Add[rt]);
		deal(rt<<1|1,Add[rt]);
		Add[rt]=0;
	}
}
inline void updata(int L,int R,int x,int l,int r,int rt)
{
	if(L<=l&&r<=R) {deal(rt,x); return ;}
	int mid=(l+r)>>1; pushdown(rt);
	if(mid>=L) updata(L,R,x,l,mid,rt<<1);
	if(mid<R) updata(L,R,x,mid+1,r,rt<<1|1);
}
inline int query(int x,int l,int r,int rt)
{
	if(l==r) return tree[rt];
	int mid=(l+r)>>1; pushdown(rt);
	if(mid>=x) return query(x,l,mid,rt<<1);
	if(mid<x) return query(x,mid+1,r,rt<<1|1);
	return 0;
}
int n,m,A[N],sum;
signed main()
{
	n=read(); m=read();
	for(int i=1;i<=n;i++) A[i]=read();
	for(int i=2;i<=n;i++)
	{
		if(A[i-1]==A[i]) continue;
		if(A[i-1]<A[i])
		{
			if(A[i-1]+2<=A[i])
				updata(A[i-1]+2,A[i],1,1,m+1,1);
			updata(A[i]+1,A[i]+1,-(A[i]-A[i-1]-1),1,m+1,1);
			sum+=A[i]-A[i-1];
		}
		else 
		{
			if(A[i-1]+2<=m)
				updata(A[i-1]+2,m,1,1,m+1,1);
			updata(1,1,m-A[i-1]-1,1,m+1,1);
			updata(1,A[i],1,1,m+1,1);
			updata(A[i]+1,A[i]+1,A[i-1]-A[i]-m+1,1,m+1,1);
			sum+=m-A[i-1]+A[i];
		}
	}
	int pr=0,Ans=1000000000000000ll;
	for(int i=1;i<=m;i++)
		pr+=query(i,1,m+1,1),
		Ans=min(Ans,sum-pr);
	cout << Ans << endl;
	return 0 ;
}
