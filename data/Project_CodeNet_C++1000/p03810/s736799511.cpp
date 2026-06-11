#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N=1e5+5;

typedef long long LL;

int n,a[N];

bool ans;

int gcd(int x,int y)
{
	return (!y)?x:gcd(y,x%y);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i,p,s;;)
	{
		for (p=s=0,i=1;i<=n;i++) if (a[i]&1) s++;else p^=1;
		if (p)
		{
			ans^=1; break;
		}
		if (s>1) break;
		for (i=1;i<=n;i++) if (a[i]&1) break;
		if (a[i]==1) break;
		a[i]--;
		s=a[1];
		for (i=2;i<=n;i++) s=gcd(s,a[i]);
		for (i=1;i<=n;i++) a[i]/=s;
		ans^=1;
	}
	if  (ans) printf("First");else printf("Second");
	return 0;
}