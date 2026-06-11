#include<cstdio>
#include<algorithm>
#define ll long long
#define lowbit(x) ((x)&-(x))
using namespace std;
const int N=2e5+5;
int n,k,tot,a[N],c[N];
ll sum[N],b[N],ans,tmp[N];
void add(int x,int y)
{
	for(;x<=tot;x+=lowbit(x)) c[x]+=y;
}
int query(int x)
{
	int ans=0;
	for(;x;x-=lowbit(x)) ans+=c[x];
	return ans;
}
void discrete()
{
	sort(tmp+1,tmp+1+n);
	tot=unique(tmp+1,tmp+1+n)-tmp-1;
	for(int i=1;i<=n;i++)
		b[i]=lower_bound(tmp+1,tmp+1+tot,b[i])-tmp;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++) tmp[i]=b[i]=sum[i]-1ll*k*i;
	for(int i=1;i<=n;i++) ans+=b[i]>=0;
	discrete();
	for(int i=1;i<=n;i++){
		ans+=query(b[i]);
		add(b[i],1);
	}
	printf("%lld",ans);
	return 0;
}