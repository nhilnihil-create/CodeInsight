#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main() {
	int n,m,p1=0,p2=0,sz=0,cnt=0;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i) {
		scanf("%d",a+i);
		cnt+=(a[i]&1);
	}
	if (cnt>2) return puts("Impossible")&&0;
	if (m==1) {
		if (n==1) puts("1\n1\n1\n");
		else printf("%d\n2\n%d %d\n",a[1],a[1]-1,1);
		return 0;
	}
	for (int i=2;i<=m;++i)
		if (a[i]&1) (a[1]&1) ? swap(a[m],a[i]) : swap(a[1],a[i]);
	if (a[1]>1) b[++sz]=a[1]-1;
	for (int i=2;i<m;++i) b[++sz]=a[i];
	b[++sz]=a[m]+1;
	for (int i=1;i<=m;++i) printf("%d ",a[i]); puts("");
	printf("%d\n",sz);
	for (int i=1;i<=sz;++i) printf("%d ",b[i]); puts("");
}