#include <cstdio>
int a[50],ans[100];
int main(){
	long long n;
	scanf("%lld",&n);n++;
	int m=0,t=0;
	for (;n>1;n>>=1) m+=(a[++t]=n&1);
	int l=m+1,r=m;
	for (int i=t,j=0;i;i--){
		ans[++r]=++j;
		if (a[i]) ans[--l]=++j;
	}
	printf("%d\n",r*2);
	for (int i=1;i<=r;i++) printf("%d ",ans[i]);
	for (int i=1;i<=r;i++) printf("%d ",i);
}