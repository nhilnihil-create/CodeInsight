#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,m,tot,a[N];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) if (a[i]&1) tot++;
	if (tot>2) return puts("Impossible"),0;
	if (tot){
		bool flag=0;
		for (int i=1;i<m;i++){
			if (a[i]&1){
				if (flag) swap(a[i],a[m]);
				else flag=1,swap(a[i],a[1]);
			}
		}
	}
	if (m==1){
		if (a[1]==1){
			printf("1\n1\n1\n");
			return 0;
		}
		printf("%d\n",a[1]);printf("2\n");
		printf("1 %d\n",a[1]-1);
		return 0;
	}
    for (int i=1;i<=m;i++) printf("%d ",a[i]);puts("");
    if (a[m]==1) printf("%d\n",m-1);else printf("%d\n",m);
    printf("%d\n",a[1]+1);
	for (int i=2;i<m;i++) printf("%d ",a[i]);
	if (a[m]>1) printf("%d\n",a[m]-1);
	return 0;
}