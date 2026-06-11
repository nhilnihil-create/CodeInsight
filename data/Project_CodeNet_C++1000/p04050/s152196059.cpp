#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int N=100005;

int n,m,cnt,t;
int a[N],b[N];

int main(){
	int i; cnt=0;
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++){
		scanf("%d",&a[i]);
		if (a[i]&1) cnt++;
	}
	if (cnt>2){
		printf("Impossible\n");
		return 0;
	}
	for (i=2;i<=m;i++)
		if (a[i]&1) (a[1]&1)?swap(a[m],a[i]):swap(a[1],a[i]);
	if (m==1){
		if (a[1]==1) printf("%d\n1\n%d\n",1,1);
		else printf("%d\n2\n%d %d\n",a[1],a[1]-1,1);
		return 0;
	}
	for (i=1;i<=m;i++) printf("%d ",a[i]); printf("\n");
	t=0;
	if (a[1]>1) b[++t]=a[1]-1;
	for (i=2;i<m;i++) b[++t]=a[i];
	b[++t]=a[m]+1;
	printf("%d\n",t);
	for (i=1;i<=t;i++) printf("%d ",b[i]);
	return 0;
}