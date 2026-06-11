#include<cstdio>
using namespace std;
int n,a[100005],sum[100005],mx,mn;
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) {scanf("%d",&a[i]);sum[a[i]]++;}
	for(int i=n;i;--i) if(sum[i]) {mx=i;break;}
	for(int i=1;i<=n;++i) if(sum[i]) {mn=i;break;}
	if(!(mx&1)&&mn==mx/2&&sum[mn]>=2) printf("Impossible");
	else if((mx&1)&&mn==mx/2+1&&sum[mn]!=2) printf("Impossible");
	else {
		for(int i=mn+1;i<=mx;++i) if(sum[i]<=1) {printf("Impossible");return 0;}
		printf("Possible");
	}
	return 0;
}