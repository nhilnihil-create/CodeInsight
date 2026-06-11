#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;
typedef long long LL;
const int maxn = 505;
const int A = 1000;

int n,m,a[maxn],stk[maxn],top;
int main()
{
	#ifdef Amberframe
		freopen("agc001d.in","r",stdin);
		freopen("agc001d.out","w",stdout);
	#endif
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++) {
		scanf("%d",&a[i]);
		if (a[i]&1) stk[++top]=i;
	}
	if (top>2) printf("Impossible");
	else {
		if (top>=1) swap(a[1],a[stk[1]]);
		if (top>=2) swap(a[m],a[stk[2]]);
		for (int i=1;i<=m;i++) printf("%d ",a[i]);
		if (m==1) {if (a[1]>1) a[m]--,a[++m]=1;}
		else a[1]++,a[m]--;a[m]==0?m--:0;
		printf("\n%d\n",m);
		for (int i=1;i<=m;i++) printf("%d ",a[i]);
	}
	return 0;
}