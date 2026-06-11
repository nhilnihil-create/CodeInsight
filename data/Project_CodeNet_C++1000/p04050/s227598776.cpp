#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 150
int n,m,a[N],b[N];
int main() {
	scanf("%d%d",&n,&m);
	int i,flg=0;
	for(i=1;i<=m;i++) scanf("%d",&a[i]),flg+=(a[i]&1);
	if(m==1&&a[1]==1) {puts("1\n1\n1\n");return 0;}
	if(m==1) {printf("%d\n2\n%d %d\n",a[1],a[1]-1,1); return 0;}
	if(flg>2) {puts("Impossible"); return 0;}
	for(i=2;i<=m;i++) {
		if(a[i]&1) {
			if(a[1]&1) swap(a[i],a[m]);
			else swap(a[i],a[1]);
		}
	}
	for(i=1;i<=m;i++) printf("%d ",a[i]); puts(""); 
	i=1;
	if(a[1]==1) i++;
	printf("%d\n",m-i+1);
	a[1]--,a[m]++;
	for(;i<=m;i++) printf("%d ",a[i]); puts("");
}
