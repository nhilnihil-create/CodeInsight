#include <bits/stdc++.h>
using namespace std;
const int N=20005;
int a[N],b[N],p[N];
int main (){
	int n;scanf ("%d",&n);
	for (int i=1;i<=n;i++) scanf ("%d",&p[i]);
	for (int i=1;i<=n;i++) a[i]=a[i-1]+20005;
	for (int i=n;i>=1;i--) b[i]=b[i+1]+20005;
	for (int i=1;i<=n;i++)
		a[p[i]]-=(n-i+1);
	for (int i=1;i<=n;i++) printf ("%d ",a[i]);
	puts("");
	for (int i=1;i<=n;i++) printf ("%d ",b[i]);
	return 0;
}
