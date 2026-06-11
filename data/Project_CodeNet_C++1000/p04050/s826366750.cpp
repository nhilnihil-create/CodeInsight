#include <algorithm>
#include <cstdio>
int a[105];
int main(){
	int n,m,x=0,y=0;
	scanf("%d%d\n",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d",&a[i]);
		if (a[i]&1){
			if (!x) x=i;
			else if (!y) y=i;
			else{
				printf("Impossible\n");
				return 0;
			}
		}
	}
	if (x) std::swap(a[1],a[x]);
	if (y) std::swap(a[y],a[m]);
	for (int i=1;i<=m;i++) printf("%d ",a[i]);
	if (m==1) ++m;
	a[1]--;a[m]++;
	int j=a[1]?1:2;
	printf("\n%d\n",m-j+1);
	for (int i=j;i<=m;i++) printf("%d ",a[i]);
}