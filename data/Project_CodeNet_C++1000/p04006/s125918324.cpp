#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2005;
long long n,x,a[maxn],b[maxn],now,ans=1e18;
int main(){
	scanf("%lld%lld",&n,&x);
	for (int i=0;i<n;i++) scanf("%lld",&a[i]);
	memset(b,63,sizeof b);
	for (int i=0;i<n;i++){
		now=x*i;
		for (int j=0;j<n;j++)
		b[j]=min(b[j],a[(i+j)%n]),now+=b[j];
		ans=min(ans,now);
	}
	printf("%lld\n",ans);
	return 0;
}