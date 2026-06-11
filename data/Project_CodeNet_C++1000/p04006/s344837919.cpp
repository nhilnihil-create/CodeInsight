#include<cstdio>
typedef long long LL;
inline void Min(int &x,int y){if(x>y)x=y;}
const int N=2003;

int n,x;
int mn[N],a[N<<1];
LL ans=1e18+233,sum;

int main() {
	scanf("%d %d",&n,&x);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		a[i+n]=a[i];
		mn[i]=0x3f3f3f3f;
	}
	for(int k=0;k<n;k++) {
		sum=1ll*k*x;
		for(int i=1;i<=n;i++) {
			Min(mn[i],a[i+k]);
			sum+=mn[i];
		}
		if(sum<ans) ans=sum;
	}
	printf("%lld\n",ans);
	return 0;
} 