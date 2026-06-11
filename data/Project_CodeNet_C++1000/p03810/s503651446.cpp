#include<bits/stdc++.h>
using namespace std;
int n,a[500010];
bool work()
{
	int even=0,odd=0;
	for (int i=1;i<=n;i++) {even+=(!(a[i]&1));odd+=(a[i]&1);}
	if (even&1) return true;
	if (odd>1) return false;
	for (int i=1;i<=n;i++) if (a[i]&1)
	{
		if (a[i]==1) return false;
		a[i]--;break;
	}
	int g=a[1];for (int i=2;i<=n;i++) g=__gcd(g,a[i]);
	for (int i=1;i<=n;i++) a[i]/=g;
	return !work();
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	puts(work()?"First":"Second");
}