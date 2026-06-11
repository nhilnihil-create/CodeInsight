#include<bits/stdc++.h>
using namespace std;
int n,m,h,w,a[502][502],v,i,j;
long long sum;
int main(){
	scanf("%d%d%d%d",&n,&m,&h,&w),v=(1-h*w)*1000-1;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++) a[i][j]=(i%h==0 && j%w==0?v:1000),sum+=a[i][j];
	if (sum<=0) return puts("No"),0;
	puts("Yes");
	for (i=1;i<=n;i++,puts(""))
		for (j=1;j<=m;j++) printf("%d ",a[i][j]);
}