#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int n,m,a[N];
#define lc x<<1
#define rc x<<1|1
ll k[N],b[N],val[N];
void add(int x,int l,int r,int L,int R,int v1,int v2){
	if (l>=L&&r<=R){k[x]+=v1;b[x]+=v2;return;}
	int mid=(l+r)>>1;
	if (L<=mid) add(lc,l,mid,L,R,v1,v2);
	if (R>mid) add(rc,mid+1,r,L,R,v1,v2);
}
void dfs(int x,int l,int r){
	if (l==r) return void(val[l]=k[x]*l+b[x]);
	int mid=(l+r)>>1;
	k[lc]+=k[x];b[lc]+=b[x];
	k[rc]+=k[x];b[rc]+=b[x];
	dfs(lc,l,mid);
	dfs(rc,mid+1,r);
}
int main()
{
	scanf("%d%d%d",&m,&n,&a[1]);
	for (int i=2;i<=m;i++){
		scanf("%d",&a[i]);
		if (a[i]==a[i-1]) continue;
		if (a[i]>a[i-1]){
			if (a[i]<n) add(1,1,n,a[i]+1,n,0,a[i]-a[i-1]);
			add(1,1,n,1,a[i-1],0,a[i]-a[i-1]);
			add(1,1,n,a[i-1]+1,a[i],-1,a[i]+1);
		}
		else{
			add(1,1,n,a[i]+1,a[i-1],0,a[i]+n-a[i-1]);
			if (a[i-1]<n) add(1,1,n,a[i-1]+1,n,-1,a[i]+n+1);
			add(1,1,n,1,a[i],-1,a[i]+1);
		}
	}
	dfs(1,1,n);
	ll ans=1e18;
	for (int i=1;i<=n;i++) ans=min(ans,val[i]);
	printf("%lld\n",ans);
	return 0;
}