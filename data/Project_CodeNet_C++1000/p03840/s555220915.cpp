#include <stdio.h>
#include <stdlib.h>
#define over(...) printf(__VA_ARGS__),exit(0)
int a[8],b[8];
long long ans=0;
int main(){
	for(int i=1;i<=7;i++)
		scanf("%d",&a[i]);
	ans+=a[2];
	ans+=a[1]&(~1); b[1]=a[1]&1;
	ans+=a[4]&(~1); b[4]=a[4]&1;
	ans+=a[5]&(~1); b[5]=a[5]&1;
	if(b[1]&&b[4]&&b[5]) over("%lld",ans+3);
	if(b[4]&&b[5]&&a[1]>0) over("%lld",ans+1);
	if(b[1]&&b[5]&&a[4]>0) over("%lld",ans+1);
	if(b[1]&&b[4]&&a[5]>0) over("%lld",ans+1);
	printf("%lld",ans);
}