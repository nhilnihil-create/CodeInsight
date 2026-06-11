#include<bits/stdc++.h>
#define LL long long
#define rep(i,l,r) for(LL i=l;i<=r;i++)
#define dep(i,r,l) for(LL i=r;i>=l;i--)
#define fy 20021218020021218
#define N 100010
using namespace std;
struct node
{
	LL num,v;
}a[N];
LL ans[N];
LL n,m,i,j,k,l,r;
LL read()
{
	LL x=0,k=1; char c;
	while(!isdigit(c=getchar())) if(c=='-') k=-k;
	x=c^48;
	while(isdigit(c=getchar())) x=(x<<1)+(x<<3)+(c^48);
	return x*k;
}
bool cmp(node a,node b){return a.v>b.v;}
int main()
{
	n=read();
	rep(i,1,n) a[i].v=read(),a[i].num=i;
	sort(a+1,a+n+1,cmp);
	i=0; j=n+1;
	a[n+2].num=fy; a[n+2].v=fy; 
	while(i<=n)
	{
		j=min(j,a[++i].num);
		while(a[i].v==a[i+1].v) j=min(j,a[++i].num);
		ans[j]+=i*(a[i].v-a[i+1].v);
	}
	rep(i,1,n) printf("%lld\n",ans[i]);
	return 0;
}