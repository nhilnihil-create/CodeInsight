#include<bits/stdc++.h>

using namespace std;

const int N=105;
int n,m,a[N],k,b[N],l;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d",&a[i]),k+=a[i]&1;
	if(k>2)puts("Impossible"),exit(0);
	for(int i=1;i<=m;i++)if(a[i]&1)swap(a[1],a[i]);
	for(int i=2;i<=m;i++)if(a[i]&1)swap(a[i],a[m]);
	for(int i=1;i<=m;i++)printf("%d ",a[i]);puts("");
	if(m==1)++m;for(int i=1;i<=m;i++)b[i]=a[i]-(i==1)+(i==m),l+=b[i]>0;
	printf("%d\n",l);for(int i=1;i<=m;i++)if(b[i])printf("%d ",b[i]);puts("");
	return 0;
}