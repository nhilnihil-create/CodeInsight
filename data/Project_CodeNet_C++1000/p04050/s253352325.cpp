#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,a[N];
int main()
{
	scanf("%d%d",&n,&m);
	int odd=0;
	for (int i=1;i<=m;i++) scanf("%d",&a[i]),odd+=(a[i]&1);
	if (odd>2) return puts("Impossible"),0;
	if (m==1){
		printf("%d\n",n);
		if (n==1) printf("1\n1\n");
			else printf("2\n%d %d\n",n-1,1);
		return 0;
	}
	for (int i=1;i<=m;i++)
		if (a[i]&1) swap(a[1],a[i]);
	for (int i=2;i<=m;i++)
		if (a[i]&1) swap(a[i],a[m]);
	for (int i=1;i<=m;i++) printf("%d ",a[i]);
	puts("");
	if (a[1]==1) printf("%d\n",m-1);
		else printf("%d\n%d ",m,a[1]-1);
	for (int i=2;i<m;i++) printf("%d ",a[i]);
	printf("%d\n",a[m]+1);
	return 0;
}