#include <bits/stdc++.h>

using namespace std;

int n,m,a[210],odd,b[210];
int main()
{
	scanf("%d%d",&n,&m); odd=0;
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]),odd+=(a[i]&1);
	if(odd>2) {printf("Impossible\n"); return 0;}
	for(int i=2;i<=m;i++)
	{
		if(a[i]%2==0) continue;
		if(a[1]%2==0) swap(a[i],a[1]);
		else swap(a[i],a[m]);
	}
	for(int i=1;i<=m;i++) printf("%d ",a[i]); printf("\n");
	if(m==1) {
		if(n==1) printf("1\n1\n");
		else printf("2\n%d %d\n",n-1,1); 
		return 0;}
	b[1]=a[1]-1;
	for(int i=2;i<m;i++) b[i]=a[i];
	b[m]=a[m]+1;
	printf("%d\n",m-(b[1]==0));
	for(int i=1+(b[1]==0);i<m;i++)
		printf("%d ",b[i]);
	if(b[m]) printf("%d\n",b[m]);
	return 0 ;
}