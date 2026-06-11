#include<cstdio>
#define int long long
#define min(a,b)((a)<(b)?(a):(b))
#define max(a,b)((a)>(b)?(a):(b))
const int N=1e5+3;
int n,m,a[N],b[N],ans1=-1e18,ans2=1e18,s;
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	  scanf("%lld",a+i),b[i]=a[i]+b[i-1];
	s=0;
	for(int i=m;i<=n;i++)s+=max(a[i],0);
	for(int i=m;i<=n;i++){
	  s=s-max(a[i],0)+max(a[i-m],0);
	  ans1=max(b[i]-b[i-m]+s,ans1);
	}
	s=0;
	for(int i=m;i<=n;i++)s+=min(a[i],0);
	for(int i=m;i<=n;i++){
	  s=s-min(a[i],0)+min(a[i-m],0);
	  ans2=min(b[i]-b[i-m]+s,ans2);
	}
	s=0;
	for(int i=1;i<=n;i++)s+=a[i];
	printf("%lld",max(ans1,s-ans2));
	return 0;
}