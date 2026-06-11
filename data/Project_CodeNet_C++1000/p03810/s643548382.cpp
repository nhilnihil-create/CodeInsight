#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef long long LL;
const int maxn = 100005;

int a[maxn],n;
int gcd(int n,int m) {
	return m?gcd(m,n%m):n;
}
bool PlayGame() {
	int even=0,odd=0;
	for (int i=1;i<=n;i++)
		a[i]&1?odd++:even++;
	if (even&1) return true;
	if (odd!=1) return false;
	int t=1;while (!(a[t]&1)) ++t;
	if (a[t]==1) return false;
	
	a[t]--;int o=a[t];
	for (int i=1;i<=n;i++) o=gcd(o,a[i]);
	for (int i=1;i<=n;i++) a[i]/=o;
	return !PlayGame();
}
int main()
{
	#ifdef Amberframe
		freopen("agc010d.in","r",stdin);
		freopen("agc010d.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("%s",PlayGame()?"First":"Second");
	return 0;
}