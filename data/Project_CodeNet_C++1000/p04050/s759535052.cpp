#include<bits/stdc++.h>
using namespace std;
#define RI register int
typedef long long LL;
int n,m,js,a[105],kl[105],b[105];
int main()
{
	scanf("%d%d",&n,&m);
	for(RI i=1;i<=m;++i) {
		scanf("%d",&a[i]);
		if(a[i]&1) kl[++js]=i;
	}
	if(js>2) {puts("Impossible");return 0;}
	if(js>=1) swap(a[kl[1]],a[1]);
	if(js>=2) swap(a[kl[2]],a[m]);
	if(m==1) {
		printf("%d\n",a[1]);
		b[1]=n/2+1;
		if(n-b[1]) puts("2"),printf("%d %d\n",b[1],n-b[1]);
		else puts("1"),printf("%d\n",b[1]);
	}
	else {
		b[1]=a[1]+1;for(RI i=2;i<m;++i) b[i]=a[i];
		for(RI i=1;i<=m;++i) printf("%d ",a[i]);
		puts("");
		if(a[m]-1) {
			printf("%d\n",m);b[m]=a[m]-1;
			for(RI i=1;i<=m;++i) printf("%d ",b[i]);
		}
		else {
			printf("%d\n",m-1);
			for(RI i=1;i<=m-1;++i) printf("%d ",b[i]);
		}
		puts("");
	}
	return 0;
}