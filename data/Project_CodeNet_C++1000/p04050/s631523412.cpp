#include<bits/stdc++.h>
using namespace std;
int a[110],flag,n,x,m;
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]),x+=a[i]%2;
	if(n==1&&a[1]==1)return printf("1\n1\n1"),0;
	if(n==1)return printf("%d\n2\n%d %d",a[1],a[1]-1,1),0;
	if(x>2)return puts("Impossible"),0;
	if(x)for(int i=1;i<=n;++i)if(a[i]%2)swap(a[i],a[flag?n:1]),flag=1;
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
	a[1]--,a[n]++;
	if(!a[1])printf("\n%d\n",n-1);
	else printf("\n%d\n",n);
	for(int i=1;i<=n;++i)if(a[i])printf("%d ",a[i]);
}