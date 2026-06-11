#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",a+i);
	sort(a+1,a+n+1,greater<int>());
	int p=1;
	while (p<n&&a[p+1]>=p+1) ++p;
	int q=p;
	while (q<n&&a[q+1]==p) ++q;
	if ((q-p&1)||(a[p]-p&1)) puts("First");
	else puts("Second");
}