#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;
typedef long long LL;
const int maxn = 251005;

int a[maxn],x[maxn],ord[maxn],pos,n;
bool comp(int u,int v) {return x[u]<x[v];}
int main()
{
	#ifdef Amberframe
		freopen("agc008d.in","r",stdin);
		freopen("agc008d.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&x[i]),a[x[i]]=i,ord[i]=i;
	sort(ord+1,ord+n+1,comp);pos=1;
	for (int i=1;i<=n;i++) {
		int t=ord[i];
		for (int j=1;j<t;j++) {
			while (a[pos]) ++pos;
			a[pos]=t;++pos;
		}
		if (pos>x[t]) {puts("No");return 0;}
	}
	for (int i=1;i<=n;i++) {
		int t=ord[i];
		for (int j=n;j>t;j--) {
			while (a[pos]) ++pos;
			if (pos<x[t]) {puts("No");return 0;}
			a[pos]=t;++pos;
		}
	}
	puts("Yes");
	for (int i=1;i<=n*n;i++)
		printf("%d ",a[i]);
	return 0;
}