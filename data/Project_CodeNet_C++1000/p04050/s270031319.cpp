#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=110;
int n,m,a[N],b[N];
int main(){
	scanf("%d%d",&n,&m);
	int odd=0;
	for(int i=1;i<=m;i++)
	  scanf("%d",&a[i]),odd+=(a[i]&1);
	if(m==1){
	  if(a[1]==1) printf("1\n1\n1\n");
	  else printf("%d\n2\n%d 1\n",a[1],a[1]-1);
	  return 0;
	}
	if(odd>2) puts("Impossible");
	else{
	  for(int i=2;i<=m;i++)
		if(a[i]&1) (a[1]&1)?swap(a[m],a[i]):swap(a[1],a[i]);
	  int t=0; if(a[1]>1) b[++t]=a[1]-1;
	  for(int i=2;i<m;i++) b[++t]=a[i];
	  b[++t]=a[m]+1;
	  for(int i=1;i<=m;i++) printf("%d ",a[i]);
	  printf("\n%d\n",t);
	  for(int i=1;i<=t;i++) printf("%d ",b[i]);
	}
}